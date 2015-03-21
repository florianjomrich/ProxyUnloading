//
// Copyright (C) 2010 Bruno Sousa
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include "Proxy_Enhanced_MCoAVideoSrv.h"
#include "UDPControlInfo_m.h"
#include "IPAddressResolver.h"
#include "BindingUpdateInformationtoAPPmessageCN.h"
#include "RequestVideoStream_m.h"

#define CN_APP_MESSAGE 50
#define PROXY_MESSAGE_FROM_CN_TO_MN 51

using std::cout;

Define_Module(Proxy_Enhanced_MCoAVideoSrv);

inline std::ostream& operator<<(std::ostream& out, const Proxy_Enhanced_MCoAVideoSrv::VideoStreamData& d) {
    out << "client=" << d.clientAddr << ":" << d.clientPort
        << "  size=" << d.videoSize << "  pksent=" << d.numPkSent << "  bytesleft=" << d.bytesLeft;
    return out;
}
Proxy_Enhanced_MCoAVideoSrv::Proxy_Enhanced_MCoAVideoSrv() {
	// TODO Auto-generated constructor stub

}

Proxy_Enhanced_MCoAVideoSrv::~Proxy_Enhanced_MCoAVideoSrv() {
	// TODO Auto-generated destructor stub
	for (unsigned int i=0; i<streamVector.size(); i++)
	        delete streamVector[i];
}

void Proxy_Enhanced_MCoAVideoSrv::initialize()
{
    cout<<"Initializing Proxy_Enhanced_MCoAVideoSrv module"<<endl;

	MCoAUDPBase::startMCoAUDPBase();

    waitInterval = &par("waitInterval");
    packetLen = &par("packetLen");
    videoSize = &par("videoSize");
    localPort = par("localPort");
    int destPort = par("destPort");
    simtime_t startTime = par("startTime");

    simtime_t hurzTime = 10;

    const char *address = par("destAddresses");
	IPvXAddress cliAddr = IPAddressResolver().resolve(address);
	if (cliAddr.isUnspecified())
	{
		EV << "Client address is unspecified, skip sending video stream request\n";
		return;
	}

    WATCH_PTRVECTOR(streamVector);

    bindToPort(localPort);

    PktSent.setName("MCOA VIDEO Packet Sent");



    //Support only for one client... extend if needed
    //FIXME:
    VideoStreamData *d = new VideoStreamData;
	d->clientAddr = cliAddr;
	d->clientPort = destPort;
	d->videoSize = (*videoSize);
	d->bytesLeft = d->videoSize;
	d->numPkSent = 0;
	d->seqTx = 0; //First Request
	streamVector.push_back(d);


   /* if (startTime>=0){
    	cMessage *timer = new cMessage("UDPVideoStart");
    	timer->setName("Proxy_Context_Message");
		//timer->setContextPointer(d);
		scheduleAt(startTime, timer);
    } */

   // cMessage *hurz = new cMessage("HURZ");
   // hurz->setKind(PROXY_CN_MESSAGE_TO_MOBILE_NODE);
   // scheduleAt(hurzTime,hurz);
}

void Proxy_Enhanced_MCoAVideoSrv::finish()
{
    //recordScalar("streams served", numStreams);
    //recordScalar("packets sent", numPkSent);
}

void Proxy_Enhanced_MCoAVideoSrv::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
    	if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR ){
			MCoAUDPBase::treatMessage(msg);

			return; // and that's it!
		}



    }

    else{

        if(dynamic_cast<RequestVideoStream*>(msg)){
            cout<<"MCoASrv: Request for sending Video received"<<endl;

            //Auslesen der Controll-Informationen - SRC und DEST IP usw. usf. zum Umsetzen des FlowSource_IP-Adressen-Konzeptes
            UDPControlInfo* myControllInfo = check_and_cast<UDPControlInfo*>(msg->getControlInfo());
            IPvXAddress srcIPAdresse = myControllInfo->getSrcAddr();
            cout<<"MCoASrv received IP-Adress: "<<srcIPAdresse<<endl;
            //TODO das hier noch mal fixen, das korrekt Daten gesendet werden dann

            //cMessage *timer = new cMessage("UDPVideoStart");
            //sendStreamData(timer);
        }

    }


}

void Proxy_Enhanced_MCoAVideoSrv::sendStreamData(cMessage *timer)
{
    //Be careful with statistics if multiple clients exist
	for (uint i=0; i< streamVector.size();i++){
		VideoStreamData *videoStreamData = streamVector[i];
		//VideoStreamData *d = (VideoStreamData *) timer->getContextPointer();

		char msgName[32];
		sprintf(msgName,"MCoAUDPVIDEO");

		// generate and send a packet
		//cPacket *pkt = new cPacket("VideoStrmPk");
		MCoAVideoStreaming *pkt_video = new MCoAVideoStreaming(msgName);
		long pktLen = packetLen->longValue();
		if (pktLen > videoStreamData->bytesLeft)
			pktLen = videoStreamData->bytesLeft;
		//pkt->setByteLength(pktLen);
		videoStreamData->seqTx = videoStreamData->seqTx +1;

		pkt_video->setByteLength(pktLen);
		pkt_video->setCurSeq(videoStreamData->seqTx);
		pkt_video->setCurTime(simTime().dbl());

		//sendToUDP(pkt, serverPort, d->clientAddr, d->clientPort);
		sendToUDPMCOA(pkt_video, localPort, videoStreamData->clientAddr, videoStreamData->clientPort, true);

		videoStreamData->bytesLeft -= pktLen;
		videoStreamData->numPkSent++;

		//Statistics
		PktSent.record(pkt_video->getCurSeq());

		// reschedule timer if there's bytes left to send
		if (videoStreamData->bytesLeft!=0)
		{
			simtime_t interval = (*waitInterval);
			scheduleAt(simTime()+interval, timer);
		}
		else
		{
			delete timer;
			// TBD find VideoStreamData in streamVector and delete it
		}
	}
}

