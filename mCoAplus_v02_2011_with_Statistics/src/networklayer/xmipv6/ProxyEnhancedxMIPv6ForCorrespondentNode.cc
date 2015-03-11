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

#include <ProxyEnhancedxMIPv6ForCorrespondentNode.h>

#define PROXY_ENHANCED_BU_MESSAGE  42

Define_Module(ProxyEnhancedxMIPv6ForCorrespondentNode);



ProxyEnhancedxMIPv6ForCorrespondentNode::ProxyEnhancedxMIPv6ForCorrespondentNode() {
    // TODO Auto-generated constructor stub
    xMIPv6();
}

ProxyEnhancedxMIPv6ForCorrespondentNode::~ProxyEnhancedxMIPv6ForCorrespondentNode() {
    // TODO Auto-generated destructor stub

}

void ProxyEnhancedxMIPv6ForCorrespondentNode::handleMessage(cMessage *msg){
    if(msg->getKind()==PROXY_ENHANCED_BU_MESSAGE){
      //  cout<< "Steuernachricht der Proxy_Enhanced_App erhalten"<<endl;
       // xMIPv6::sendPeriodicBU(msg);
    }
    else{
       //cout << "### ANDERE NACHRICHT ERHALTEN ###" <<endl;
       xMIPv6::handleMessage(msg);
    }

}

void ProxyEnhancedxMIPv6ForCorrespondentNode::processBUMessage(BindingUpdate* bu, IPv6ControlInfo* ctrlInfo)
{

    IPv6Address& CoA = ctrlInfo->getSrcAddr();
    IPv6Address& destAddress = ctrlInfo->getDestAddr();
    IPv6Address& HoA =    bu->getHomeAddressMN();
    xMIPv6::processBUMessage(bu,ctrlInfo);
    cout<<"CorrespondentNode hat Binding Update vom MN empfangen HoA: "<<HoA << " CoA: "<< CoA<<"  desAddress:" << destAddress <<"Full Name"<< fullname<<endl;

     cMessage* msg = new cMessage();
                      msg->setName("Message for the CN UDP APP SERVER");
                      send(msg, "xMIP_proxy_Enhanced_Control_Channel_CN$o",0); //$o muss angegeben werden um über einen inout-Port etwas nach draußen senden zu können*/
                      cout<<"HALLO WELT"<<endl;
}

