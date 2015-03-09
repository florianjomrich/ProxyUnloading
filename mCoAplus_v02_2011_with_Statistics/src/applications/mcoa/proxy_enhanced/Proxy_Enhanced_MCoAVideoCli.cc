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

#include "Proxy_Enhanced_MCoAVideoCli.h"
#include "UDPControlInfo_m.h"
#include "IPAddressResolver.h"

using std::cout;

Define_Module(Proxy_Enhanced_MCoAVideoCli);

inline std::ostream& operator<<(std::ostream& out, const Proxy_Enhanced_MCoAVideoCli::VideoStreamData& d) {
    out << "client=" << d.clientAddr << ":" << d.clientPort
        << "  size=" << d.videoSize << "  pksent=" << d.numPkSent << "  bytesleft=" << d.bytesLeft;
    return out;
}
Proxy_Enhanced_MCoAVideoCli::Proxy_Enhanced_MCoAVideoCli() {
	// TODO Auto-generated constructor stub

}

Proxy_Enhanced_MCoAVideoCli::~Proxy_Enhanced_MCoAVideoCli() {
	// TODO Auto-generated destructor stub
	for (unsigned int i=0; i<streamVector.size(); i++)
	        delete streamVector[i];
}

void Proxy_Enhanced_MCoAVideoCli::initialize()
{
	MCoAUDPBase::startMCoAUDPBase();

   // waitInterval = &par("waitInterval");
  //  packetLen = &par("packetLen");
   // videoSize = &par("videoSize");
    localPort = par("localPort");
    int destPort = par("destPort");
    simtime_t startTime = par("startTime");

  //  const char *address = par("CN[0]");

	//cout<< "CLIENT ADDRESS:"<<cliAddr<<endl;
	//if (cliAddr.isUnspecified())
	//{
	/////	return;
	//}

    WATCH_PTRVECTOR(streamVector);

    bindToPort(localPort);

    PktSent.setName("MCOA VIDEO Packet Sent");



    //Support only for one client... extend if needed
    //FIXME:
   // VideoStreamData *d = new VideoStreamData;
	//d->clientAddr = cliAddr;
	//d->clientPort = destPort;
	//d->videoSize = (*videoSize);
	//d->bytesLeft = d->videoSize;
	//d->numPkSent = 0;
	//d->seqTx = 0; //First Request
	//streamVector.push_back(d);


    if (startTime>=0){
    	cMessage *timer = new cMessage("UDPVideoStart");
		//timer->setContextPointer(d);
		scheduleAt(startTime, timer);
    }
}

void Proxy_Enhanced_MCoAVideoCli::finish()
{
    //recordScalar("streams served", numStreams);
    //recordScalar("packets sent", numPkSent);
}

void Proxy_Enhanced_MCoAVideoCli::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage())
    {
    	if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR ){
			MCoAUDPBase::treatMessage(msg);

			return; // and that's it!
		}

        // timer for a particular video stream expired, send packet
    	sendControlData(msg);
    }

}
void Proxy_Enhanced_MCoAVideoCli::sendControlData(cMessage *timer)
{
    cout<<"@@ Send Control Data @@" << endl;
    IPvXAddress cliAddr = IPAddressResolver().resolve("HA");
    cout<<"@@ HA-Adress:" << cliAddr << endl;
    cPacket *buPaket = new cPacket();
    buPaket->setName("HALLO WELT");

    sendToUDPMCOA(buPaket, localPort, cliAddr, 1000, true);
}


void Proxy_Enhanced_MCoAVideoCli::sendStreamData(cMessage *timer)
{
    //Be careful with statistics if multiple clients exist
	for (uint i=0; i< streamVector.size();i++){
		VideoStreamData *d = streamVector[i];
		//VideoStreamData *d = (VideoStreamData *) timer->getContextPointer();

		char msgName[32];
		sprintf(msgName,"MCoAUDPVIDEO");

		// generate and send a packet
		//cPacket *pkt = new cPacket("VideoStrmPk");
		MCoAVideoStreaming *pkt_video = new MCoAVideoStreaming(msgName);
		long pktLen = packetLen->longValue();
		if (pktLen > d->bytesLeft)
			pktLen = d->bytesLeft;
		//pkt->setByteLength(pktLen);
		d->seqTx = d->seqTx +1;

		pkt_video->setByteLength(pktLen);
		pkt_video->setCurSeq(d->seqTx);
		pkt_video->setCurTime(simTime().dbl());

		//sendToUDP(pkt, serverPort, d->clientAddr, d->clientPort);
		sendToUDPMCOA(pkt_video, localPort, d->clientAddr, d->clientPort, true);

		d->bytesLeft -= pktLen;
		d->numPkSent++;

		//Statistics
		PktSent.record(pkt_video->getCurSeq());

		// reschedule timer if there's bytes left to send
		if (d->bytesLeft!=0)
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

