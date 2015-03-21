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

#include "Proxy_Unloading_Control_App.h"
#include "IPAddressResolver.h"
#include "IPv6ControlInfo.h"



#define PROXY_ENHANCED_BU_MESSAGE  42
#define PROXY_CN_MESSAGE_TO_MOBILE_NODE 43
#define PROXY_MESSAGE_FROM_CN_TO_MN 51
#define REQUEST_FOR_CONNECTION_TO_LEGACY_SERVER 145
#define REQUEST_FOR_CONNECTION_TO_LEGACY_SERVER_CONTROL_APP 146

using std::cout;

Define_Module(Proxy_Unloading_Control_App);

void Proxy_Unloading_Control_App::initialize() {
    //PROXY UNLOADING FJ
    cout << "Initializing Proxy_Unloading_Control_App module" << endl;
    isMN = par("isMN");
    isHA = par("isHA");
    isCN = par("isCN");
    isCapableCN = par("isCapableCN");

    startTime = par("startTime");
    cout << "START ZEIT: " << startTime << endl;

    MCoAUDPBase::startMCoAUDPBase();

    PktRcv.setName("MCOA VIDEO Packet Rcv");
    PktLost.setName("MCOA VIDEO Packet Lost");
    PktDelay.setName("MCOA VIDEO Delay");

    lastSeq = 0;

    int localPort = par("localPort");
    bindToPort(localPort);

    if (startTime >= 0 && isMN) {
        cMessage *start_proxying_context = new cMessage(
                "Starting_Proxying_Context through the Mobile Node");
        //timer->setContextPointer(d);
        start_proxying_context->setKind(PROXY_CONTEXT_START);
        scheduleAt(startTime, start_proxying_context);
    }

}

void Proxy_Unloading_Control_App::finish() {
    //Delete StatsPkt
    StatsPkt.clear();

}

void Proxy_Unloading_Control_App::handleMessage(cMessage* msg) {
    cout << "PROXY CONTROL APP of: MN:" << isMN <<" HA:"<< isHA <<" CN:"<< isCN <<" received a message"<< endl;

    if (msg->isSelfMessage()) {
        if (msg->getKind() == MK_REMOVE_ADDRESS_PAIR) {
            MCoAUDPBase::treatMessage(msg);

            return; // and that's it!
        }

    } else {

        if (dynamic_cast<RequetConnectionToLegacyServer*>(msg)) {
           // cout << "isMN: " << isMN << "  isHA: " << isHA << "   isCN: "
          //          << isCN << endl;
            if (isMN) {

                cout
                        << "Netzwerkschicht des MN meldet ein Paket, dessen Server noch nicht auf ProxyUnloading-Funktionalität hin überprüft wurde"
                        << endl;
                IPvXAddress ha = IPAddressResolver().resolve("HA");

                RequetConnectionToLegacyServer* messageAnHA = check_and_cast<
                        RequetConnectionToLegacyServer *>(msg);

                sendToUDPMCOA(messageAnHA, localPort, ha, 2000, true);
                return;
            }
            if (isHA) {
                RequetConnectionToLegacyServer* messageToCN = check_and_cast<
                        RequetConnectionToLegacyServer *>(msg);
                cout << "HA hat folgende Nachricht erhalten:"
                        << messageToCN->getName() << " mit Destination: "
                        << messageToCN->getDestAddress()
                        << " und FlowSourceAdresse: "
                        << messageToCN->getFlowSourceAddress() << endl;
                cout << "HA hat neue Anfrage erhalten von einem MN" << endl;

                IPvXAddress* cn = new IPvXAddress(
                        messageToCN->getDestAddress());
                messageToCN->removeControlInfo(); //new ipv6 control info of the home Agent is needed to send the data properly to the correspondent node
                sendToUDPMCOA(messageToCN, localPort, *cn, 2000, true);
                return;
            }
            if (isCN) {
                RequetConnectionToLegacyServer* messageFromHA = check_and_cast<
                        RequetConnectionToLegacyServer *>(msg);
                cout << "Nun hat auch der CN mit der Adresse:"
                        << messageFromHA->getDestAddress()
                        << " die RequetConnectionToLegacyServer-Nachricht erhalten" << endl;
                cout<<"Absender war: "<<messageFromHA->getSrcAddress()<<endl;
                //IPvXAddress mn0 = IPAddressResolver().resolve("MN[0]");
                //cout<<"Zum Vergleich MN[0]"<<mn0<<endl;

                //update the FlowBindingTable with this Information now for later Processing - If CN is capable of dealing with the ProxyUnloading-Protocol
                if(isCapableCN){
                    cout<<"CN supports the protocol and is actualizing his own FlowBindingTable"<<endl;
                    send(messageFromHA,"uDPControllAppConnection$o");

                    //send back a binding Acknowledgment to the HomeAgent and the MN who requested the call
                    ACK_RequestConnectionToLegacyServer* acknowledgmentToHA = new ACK_RequestConnectionToLegacyServer();
                    acknowledgmentToHA->setSrcAddress(messageFromHA->getSrcAddress());
                    acknowledgmentToHA->setDestAddress(messageFromHA->getDestAddress());
                    acknowledgmentToHA->setFlowSourceAddress(messageFromHA->getFlowSourceAddress());
                    acknowledgmentToHA->setDestPort(messageFromHA->getDestPort());
                    acknowledgmentToHA->setSrcPort(messageFromHA->getSrcPort());
                    acknowledgmentToHA->setName("ACK_RequestConnectionToLegacyServer");
                    IPvXAddress ha = IPAddressResolver().resolve("HA");
                    sendToUDPMCOA(acknowledgmentToHA,localPort,ha,2000,true);

                    ACK_RequestConnectionToLegacyServer* acknowledgmentToMN = new ACK_RequestConnectionToLegacyServer();
                    acknowledgmentToMN->setSrcAddress(messageFromHA->getSrcAddress());
                    acknowledgmentToMN->setDestAddress(messageFromHA->getDestAddress());
                    acknowledgmentToMN->setFlowSourceAddress(messageFromHA->getFlowSourceAddress());
                    acknowledgmentToMN->setDestPort(messageFromHA->getDestPort());
                    acknowledgmentToMN->setSrcPort(messageFromHA->getSrcPort());
                    acknowledgmentToMN->setName("ACK_RequestConnectionToLegacyServer");
                    IPvXAddress mn = IPvXAddress();
                    mn.set(messageFromHA->getSrcAddress());
                    sendToUDPMCOA(acknowledgmentToMN,localPort,mn,2000,true);

                }
                return;
            }

        }

        //**********************************************************************

        if (dynamic_cast<ACK_RequestConnectionToLegacyServer*>(msg)) {
            if(isHA || isMN){
                //the flow-Binding-Table on the network layer has to be updated for the MN and the HA as well
                send(msg,"uDPControllAppConnection$o");
            }
            return;
        }

        //**********************************************************************

        if(dynamic_cast<FlowBindingUpdate*>(msg)){
            if(isMN){//New Binding Update message
                cout<<"Proxy Unloading Control App of MN sends FlowBindingUpdate to HA"<<endl;
                FlowBindingUpdate* messageFromIPLayer = check_and_cast<
                        FlowBindingUpdate *>(msg);

                FlowBindingUpdate* flowBindingUpdateToHA = new FlowBindingUpdate();
                flowBindingUpdateToHA->setName("FlowBindingUpdate");
                flowBindingUpdateToHA->setHomeAddress(messageFromIPLayer->getHomeAddress());
                flowBindingUpdateToHA->setNewCoAdress(messageFromIPLayer->getNewCoAdress());
                flowBindingUpdateToHA->setDestAddress(messageFromIPLayer->getDestAddress());
                flowBindingUpdateToHA->setWasSendFromHA(false);//for avoiding infinite loop at HomeAgent
                IPvXAddress ha = IPAddressResolver().resolve("HA");
                sendToUDPMCOA(flowBindingUpdateToHA,localPort,ha,2000,true);
                //Timer anwerfen, wenn der HA ggf. die Nachricht nicht erhalten hat.

                return;
            }
            if(isHA){
                cout<<"HA hat FlowBindingUpdate vom MN erhalten und leitet dieses jetzt entsprechend an die CNs weiter"<<endl;


                FlowBindingUpdate* messageFromMN = check_and_cast<
                                FlowBindingUpdate *>(msg);

                //UPDATE OWN TABLE

                //TODO




                //INFORM The CNs in the list of the update
                FlowBindingUpdate* flowBindingUpdateToCN = new FlowBindingUpdate();
                flowBindingUpdateToCN->setName("FlowBindingUpdate");
                flowBindingUpdateToCN->setHomeAddress(messageFromMN->getHomeAddress());
                flowBindingUpdateToCN->setNewCoAdress(messageFromMN->getNewCoAdress());
                flowBindingUpdateToCN->setDestAddress(messageFromMN->getDestAddress());
                flowBindingUpdateToCN->setWasSendFromHA(true);

                IPvXAddress ha = IPAddressResolver().resolve("HA");
                IPvXAddress* dest = new IPvXAddress(messageFromMN->getDestAddress());
                cout<<"Home Address: "<<ha<<" Destination Address: "<<dest<< endl;
                if(messageFromMN->getWasSendFromHA()){//do not foreward self message --> otherwise infinite loop
                    sendToUDPMCOA(flowBindingUpdateToCN,localPort,*dest,2000,true);
                return;
                }

                IPvXAddress *mn = new IPvXAddress(messageFromMN->getNewCoAdress());
                ACK_FlowBindingUpdate* flowBindingAckToMN = new ACK_FlowBindingUpdate();
                flowBindingAckToMN->setName("ACK_FlowBindingUpdate");
                flowBindingAckToMN->setHomeAddress(messageFromMN->getHomeAddress());
                flowBindingAckToMN->setNewCoAdress(messageFromMN->getNewCoAdress());
                flowBindingAckToMN->setDestAddress(messageFromMN->getDestAddress());
                flowBindingAckToMN->setWasSendFromHA(true);
                sendToUDPMCOA(flowBindingAckToMN,localPort,*mn,2000,true);

                return;
            }
            if(isCN){

                return;
            }
        }

        //**********************************************************************


        if(dynamic_cast<ACK_FlowBindingUpdate*>(msg)){
            if(isMN){
                cout<<"MN hat BindingUpdate Nachricht bestätigt bekommen - nun kann er den Timer für erneutes Senden löschen"<<endl;
            }
        }


        if (isHA) {
            cout << "HA hat folgende Nachricht erhalten:" << msg->getName()
                    << endl;
        }

        if (isCN)
            cout << "CN hat folgende Nachricht erhalten:" << msg->getName()
                    << endl;
        if (isMN)
            cout << "MN hat folgende Nachricht erhalten:" << msg->getName()
                    << endl;
        return;

    }
}





