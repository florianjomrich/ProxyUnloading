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

#ifndef REQESTFORCONNECTIONTOLEGACYSERVERPACKET_H_
#define REQESTFORCONNECTIONTOLEGACYSERVERPACKET_H_

#include <cmessage.h>
#include <IPv6Address.h>

class RequestForConnectionToLegacyServerPacket: public cPacket {
public:
    IPv6Address sourceAddress;
    IPv6Address destinationAddress;
    int sourcePort;
    int destinationPort;
    IPv6Address flowSourceAddress;


    RequestForConnectionToLegacyServerPacket();
    virtual ~RequestForConnectionToLegacyServerPacket();

    virtual void setSrcAddress( IPv6Address& srcAddress);
    virtual void setDestAddress( IPv6Address& destAddress);
    virtual void setFlowSourceAddress( IPv6Address& flowSourceAddress);
    virtual void setSrcPort(int sPort);
    virtual void setDestPort(int destPort);

};

#endif /* REQESTFORCONNECTIONTOLEGACYSERVERPACKET_H_ */
