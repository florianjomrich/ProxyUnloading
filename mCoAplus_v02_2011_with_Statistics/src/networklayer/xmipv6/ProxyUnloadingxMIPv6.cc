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

#include <ProxyUnloadingxMIPv6.h>

#define PROXY_ENHANCED_BU_MESSAGE  42

Define_Module(ProxyUnloadingxMIPv6);



ProxyUnloadingxMIPv6::ProxyUnloadingxMIPv6() {
    // TODO Auto-generated constructor stub
    xMIPv6();
}

ProxyUnloadingxMIPv6::~ProxyUnloadingxMIPv6() {
    // TODO Auto-generated destructor stub

}

void ProxyUnloadingxMIPv6::handleMessage(cMessage *msg){
    if(msg->getKind()==PROXY_ENHANCED_BU_MESSAGE){
        cout<< "Steuernachricht der Proxy_Enhanced_App erhalten"<<endl;
       // xMIPv6::sendPeriodicBU(msg);
    }
    else{
      // cout << "### ANDERE NACHRICHT ERHALTEN ###" <<endl;
       xMIPv6::handleMessage(msg);
    }

}
