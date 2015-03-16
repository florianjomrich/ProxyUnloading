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

#include <ProxyEnhancedxMIPv6ForHomeAgent.h>

#define PROXY_ENHANCED_BU_MESSAGE  42

Define_Module(ProxyEnhancedxMIPv6ForHomeAgent);



ProxyEnhancedxMIPv6ForHomeAgent::ProxyEnhancedxMIPv6ForHomeAgent() {
    // TODO Auto-generated constructor stub
    xMIPv6();
}

ProxyEnhancedxMIPv6ForHomeAgent::~ProxyEnhancedxMIPv6ForHomeAgent() {
    // TODO Auto-generated destructor stub

}

void ProxyEnhancedxMIPv6ForHomeAgent::handleMessage(cMessage *msg){
    if(msg->getKind()==PROXY_ENHANCED_BU_MESSAGE){
        cout<< "!! Proxy Binding Update Nachricht vom Mobile Node auf der Netzwerkebene des Home Agents erhalten !!"<<endl;
       // send(msg, "xMIP_proxy_Enhanced_Control_Channel_HA[0]$o");
        send(msg, "XMIP_LAYER_HA_TO_MN$o",0);
       // xMIPv6::sendPeriodicBU(msg);
    }
    else{
      // cout << "### ANDERE NACHRICHT ERHALTEN ###" <<endl;
       xMIPv6::handleMessage(msg);
    }

}
