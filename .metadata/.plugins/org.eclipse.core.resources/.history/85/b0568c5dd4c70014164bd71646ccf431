//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <ProxyEnhancedxMIPv6ForMobileNode.h>

#define PROXY_ENHANCED_BU_MESSAGE  42

Define_Module(ProxyEnhancedxMIPv6ForMobileNode);



ProxyEnhancedxMIPv6ForMobileNode::ProxyEnhancedxMIPv6ForMobileNode() {
    // TODO Auto-generated constructor stub
    xMIPv6();
}

ProxyEnhancedxMIPv6ForMobileNode::~ProxyEnhancedxMIPv6ForMobileNode() {
    // TODO Auto-generated destructor stub

}

void ProxyEnhancedxMIPv6ForMobileNode::handleMessage(cMessage *msg){
    if(msg->getKind()==PROXY_ENHANCED_BU_MESSAGE){
        cout<< "!! Steuernachricht der Proxy_Enhanced_App erhalten auf der Netzwerkebene des Mobile Nodes !!"<<endl;
       // xMIPv6::sendPeriodicBU(msg);
        cMessage* msg = new cMessage();
                   msg->setName("Message for the HomeAgent");
                   msg->setKind(PROXY_ENHANCED_BU_MESSAGE);
                   send(msg, "XMIP_LAYER_HA_TO_MN$o"); //$o muss angegeben werden um über einen inout-Port etwas nach draußen senden zu können

    }
    else{
       //cout << "### ANDERE NACHRICHT ERHALTEN ###" <<endl;
       xMIPv6::handleMessage(msg);
    }

}
