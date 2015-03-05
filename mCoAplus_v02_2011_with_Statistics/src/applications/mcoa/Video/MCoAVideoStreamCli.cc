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

#include "MCoAVideoStreamCli.h"
#include "IPAddressResolver.h"


Define_Module(MCoAVideoStreamCli);


void MCoAVideoStreamCli::initialize()
{
	MCoAUDPBase::startMCoAUDPBase();

	PktRcv.setName("MCOA VIDEO Packet Rcv");
	PktLost.setName("MCOA VIDEO Packet Lost");
	PktDelay.setName("MCOA VIDEO Delay");
    simtime_t startTime = par("startTime");
    lastSeq=0;
    if (startTime>=0)
        scheduleAt(startTime, new cMessage("UDPVideoStreamStart"));
}

void MCoAVideoStreamCli::finish()
{
	//Delete StatsPkt
	StatsPkt.clear();

}

void MCoAVideoStreamCli::handleMessage(cMessage* msg)
{
    if (msg->isSelfMessage())
    {
    	if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR ){
			MCoAUDPBase::treatMessage(msg);

			return; // and that's it!
		}else {
			delete msg;
			requestStream();
		}
    }
    else
    {
    	if (dynamic_cast<MCoAVideoStreaming*>(msg)){
    		receiveStream(PK(msg));
    	}
    }
}

void MCoAVideoStreamCli::requestStream()
{
    int svrPort = par("destPort");
    int localPort = par("localPort");
    const char *address = par("destAddresses");
    IPvXAddress svrAddr = IPAddressResolver().resolve(address);
    if (svrAddr.isUnspecified())
    {
        EV << "Server address is unspecified, skip sending video stream request\n";
        return;
    }

    EV << "Requesting video stream from " << svrAddr << ":" << svrPort << "\n";

    bindToPort(localPort);

    cPacket *msg = new cPacket("VideoStrmReq");
    sendToUDPMCOA(msg, localPort, svrAddr, svrPort);
}

void MCoAVideoStreamCli::receiveStream(cPacket *msg)
{
	MCoAVideoStreaming *pkt_video = (MCoAVideoStreaming *)(msg);
    EV << "Video stream packet:\n";
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

