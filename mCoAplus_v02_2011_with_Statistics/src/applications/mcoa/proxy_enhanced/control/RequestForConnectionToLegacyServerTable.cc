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

/**
 * Class makes sure, that each Request to A Legacy Server is performed just once
 */

#include <RequestForConnectionToLegacyServerTable.h>

RequestForConnectionToLegacyServerTable::RequestForConnectionToLegacyServerTable() {
    // TODO Auto-generated constructor stub

}

RequestForConnectionToLegacyServerTable::~RequestForConnectionToLegacyServerTable() {
    // TODO Auto-generated destructor stub
}


bool RequestForConnectionToLegacyServerTable::containsRequestAlready(int& dport,int& sport,IPv6Address& destAddress,IPv6Address& srcAddress,IPv6Address* flowSourceAddress){
    const bool destinationPortExists = this->destinationPorts.find(dport) != destinationPorts.end();
    const bool sourcePortExists = this->sourcePorts.find(sport) != sourcePorts.end();

    return destinationPortExists && sourcePortExists;
}
void RequestForConnectionToLegacyServerTable::setRequest(int& dport,int& sport,IPv6Address& destAddress,IPv6Address& srcAddress,IPv6Address* flowSourceAddress){
    destinationPorts.insert(dport);
    sourcePorts.insert(sport);
}
