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

#ifndef REQUESTFORCONNECTIONTOLEGACYSERVERTABLE_H_
#define REQUESTFORCONNECTIONTOLEGACYSERVERTABLE_H_

#include "IPv6Address.h"

class RequestForConnectionToLegacyServerTable {
public:
    std::set<int> destinationPorts;
    std::set<int> sourcePorts;


    RequestForConnectionToLegacyServerTable();
    virtual ~RequestForConnectionToLegacyServerTable();
    virtual bool containsRequestAlready(int& dport,int& sport,IPv6Address& destAddress,IPv6Address& srcAddress, IPv6Address* flowSourceAddress);
    virtual void setRequest(int& dport,int& sport,IPv6Address& destAddress,IPv6Address& srcAddress, IPv6Address* flowSourceAddress);
};

#endif /* REQUESTFORCONNECTIONTOLEGACYSERVERTABLE_H_ */
