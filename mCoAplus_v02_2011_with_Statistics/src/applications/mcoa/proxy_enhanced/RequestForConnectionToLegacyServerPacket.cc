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

#include <RequestForConnectionToLegacyServerPacket.h>

RequestForConnectionToLegacyServerPacket::RequestForConnectionToLegacyServerPacket() {
    // TODO Auto-generated constructor stub

}

RequestForConnectionToLegacyServerPacket::~RequestForConnectionToLegacyServerPacket() {
    // TODO Auto-generated destructor stub
}



void RequestForConnectionToLegacyServerPacket::setSrcAddress(IPv6Address& srcAddress){
    this->sourceAddress=srcAddress;
}

void RequestForConnectionToLegacyServerPacket::setDestAddress(IPv6Address& destAddress){
    this->destinationAddress=destAddress;
}

void RequestForConnectionToLegacyServerPacket::setFlowSourceAddress(IPv6Address& flAddress){
    this->flowSourceAddress=flAddress;
}


void RequestForConnectionToLegacyServerPacket::setSrcPort(int srcPort){
    this->sourcePort=srcPort;
}


void RequestForConnectionToLegacyServerPacket::setDestPort(int destPort){
    this->destinationPort=destPort;
}

