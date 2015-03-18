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


//
// based on the video streaming app of the similar name by Johnny Lai
//

#include "Proxy_Enhanced_MCoAVideoCli.h"
#include "IPAddressResolver.h"
#include "IPv6ControlInfo.h"
#include "RequestVideoStream_m.h"


#define PROXY_ENHANCED_BU_MESSAGE  42
#define PROXY_CN_MESSAGE_TO_MOBILE_NODE 43
#define PROXY_MESSAGE_FROM_CN_TO_MN 51

using std::cout;

Define_Module(Proxy_Enhanced_MCoAVideoCli);


void Proxy_Enhanced_MCoAVideoCli::initialize()
{
    //PROXY UNLOADING FJ
    cout<<"Initializing Proxy_Enhanced_MCoAVideoCli module"<<endl;
    startTime = par("startTime");


	MCoAUDPBase::startMCoAUDPBase();

	PktRcv.setName("MCOA VIDEO Packet Rcv");
	PktLost.setName("MCOA VIDEO Packet Lost");
	PktDelay.setName("MCOA VIDEO Delay");

    lastSeq=0;

    int localPort = par("localPort");
    bindToPort(localPort);

    if (startTime>=0){
        cMessage *start_proxying_context = new cMessage("Starting_Proxying_Context MCoAVideoCli");
        //timer->setContextPointer(d);
        start_proxying_context->setKind(PROXY_CONTEXT_START);
        scheduleAt(startTime, start_proxying_context);
    }

}

void Proxy_Enhanced_MCoAVideoCli::finish()
{
	//Delete StatsPkt
	StatsPkt.clear();

}

void Proxy_Enhanced_MCoAVideoCli::handleMessage(cMessage* msg)
{
    if (msg->isSelfMessage())
    {
    	if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR ){
			MCoAUDPBase::treatMessage(msg);

			return; // and that's it!
		}
    	if(msg->getKind()== PROXY_CONTEXT_START){
    	    cout<<"!! Proxying Context Started !!"<<endl;
    	    sendControlData(msg);
    	    }



    }
    else
    {
    	if (dynamic_cast<MCoAVideoStreaming*>(msg)){
    		receiveStream(PK(msg));
    	}

    	else{
    	    cout<<"VIDEO CLIENT received: "<<msg->getName()<<endl;
    	}
    }
}

void Proxy_Enhanced_MCoAVideoCli::sendControlData(cMessage* msg){
    IPvXAddress cn = IPAddressResolver().resolve("CN[0]");

    RequestVideoStream* requestVideoStream = new RequestVideoStream();
    requestVideoStream->setName("MCoACli (MN) requests Video Stream from MCoASrv (CN).");

    sendToUDPMCOA(requestVideoStream, localPort, cn, 1000, true);//Port 1000 für Video - Port 2000 für Kontrolldaten

}

void Proxy_Enhanced_MCoAVideoCli::receiveStream(cPacket *msg)
{
	MCoAVideoStreaming *pkt_video = (MCoAVideoStreaming *)(msg);
    //cout << "Video stream packet:\n";
    int nLost;

    nLost = (pkt_video->getCurSeq() - lastSeq);
    nLost < 0 ? nLost * (-1) : nLost;

    long auxseqRx = pkt_video->getCurSeq();
    SPkt::iterator pos = StatsPkt.find(auxseqRx);
	if (pos != StatsPkt.end()) {
		bool pktTreated;
		pktTreated = (pos->second).treated;

		if (!pktTreated){
			(pos->second).treated = true;
			(pos->second).delay = pkt_video->getCurTime();
			PktRcv.record(auxseqRx);
			//pktRcvDelay.record(packet->getCurTime());
			PktDelay.record(simTime().dbl() - pkt_video->getCurTime());
		}
	}else{//Insert packet into structure
		EV << "MCOA Video Inserting packet into Stats structure" << endl;
		statPacketVIDEO auxS;
		auxS.seq = auxseqRx;
		auxS.treated = true;
		auxS.delay = pkt_video->getCurTime();
		StatsPkt.insert( std::make_pair(auxseqRx, auxS));

		PktRcv.record(auxseqRx);
		//pktRcvDelay.record(packet->getCurTime());
		PktDelay.record(simTime().dbl() - pkt_video->getCurTime());
	}



    /*
     * May not be always true, since it can arrive unordered,
     * just to have a notation when happens the worst packet loss
     *
     * to determine packet loss do: sent - Rcv
     */
    if ((nLost) > 1){
    	// There is packet loss
    	PktLost.record(nLost);
    	EV << "There was packet loss " << nLost << " at Sim time " << simTime() <<  endl;
    }
    //PktRcv.record(pkt_video->getCurSeq());
    //PktDelay.record(simTime().dbl() - pkt_video->getCurTime());
    lastSeq = pkt_video->getCurSeq();



    delete msg;
}

