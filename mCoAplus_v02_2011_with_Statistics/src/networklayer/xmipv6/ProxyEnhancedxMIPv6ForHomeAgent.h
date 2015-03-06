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

#ifndef PROXYENHANCEDXMIPV6_H_
#define PROXYENHANCEDXMIPV6_H_

#include <xMIPv6.h>

class ProxyEnhancedxMIPv6ForHomeAgent: public xMIPv6 {
public:
    ProxyEnhancedxMIPv6ForHomeAgent();
    virtual ~ProxyEnhancedxMIPv6ForHomeAgent();
    virtual void handleMessage(cMessage *msg);
};

#endif /* PROXYENHANCEDXMIPV6_H_ */
