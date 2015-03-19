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

#include "FlowBindingTable.h"
#include "RequetConnectionToLegacyServer_m.h"

Define_Module(FlowBindingTable);

using std::cout;

FlowBindingTable::FlowBindingTable() {
    // TODO Auto-generated constructor stub

}

FlowBindingTable::~FlowBindingTable() {
    // TODO Auto-generated destructor stub
}

void FlowBindingTable::handleMessage(cMessage* msg)
{
    if (msg->isSelfMessage())
    {


    }
    else
    {
        /*
         * A new entry has to be created
         */
        if (dynamic_cast<RequetConnectionToLegacyServer*>(msg)) {

        }
    }
}

void  FlowBindingTable::insertNewFlowBindingEntry(RequetConnectionToLegacyServer *newFlowBindingEntry){
    srcPorts.insert ( std::pair<const char*,int>(newFlowBindingEntry->getFlowSourceAddress(),newFlowBindingEntry->getSrcPort()) );
    destPorts.insert ( std::pair<const char*,int>(newFlowBindingEntry->getFlowSourceAddress(),newFlowBindingEntry->getDestPort()) );

    std::set<const char*> mySrcAdressSet;
    mySrcAdressSet.insert(newFlowBindingEntry->getSrcAddress());
    srcAdresses.insert ( std::pair<const char*,std::set<const char*> >(newFlowBindingEntry->getFlowSourceAddress(),mySrcAdressSet) );

    std::set<const char*> myDestAdressSet;
    mySrcAdressSet.insert(newFlowBindingEntry->getDestAddress());
    destAdresses.insert ( std::pair<const char*,std::set<const char*> >(newFlowBindingEntry->getFlowSourceAddress(),myDestAdressSet) );


}

FlowBindingEntry FlowBindingTable::getFlowBindingEntryFromTable(const char* flowSourceAdress){
    const bool srcPortFound = this->srcPorts.find(flowSourceAdress) != srcPorts.end();

    if(srcPortFound){
        cout<<"FlowBinding entry was found"<<endl;
        //cout<<"source Port found:"<<searchSrcPort->second<<" for Key:"<<searchSrcPort->first<<endl;
    }
}
