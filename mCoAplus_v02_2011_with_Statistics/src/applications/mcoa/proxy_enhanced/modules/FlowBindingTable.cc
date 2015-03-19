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
    myDestAdressSet.insert(newFlowBindingEntry->getDestAddress());
    destAdresses.insert ( std::pair<const char*,std::set<const char*> >(newFlowBindingEntry->getFlowSourceAddress(),myDestAdressSet) );


}

void  FlowBindingTable::insertNewFlowBindingEntry(ACK_RequestConnectionToLegacyServer *newFlowBindingEntry){
    srcPorts.insert ( std::pair<const char*,int>(newFlowBindingEntry->getFlowSourceAddress(),newFlowBindingEntry->getSrcPort()) );
    destPorts.insert ( std::pair<const char*,int>(newFlowBindingEntry->getFlowSourceAddress(),newFlowBindingEntry->getDestPort()) );

    std::set<const char*> mySrcAdressSet;
    mySrcAdressSet.insert(newFlowBindingEntry->getSrcAddress());
    srcAdresses.insert ( std::pair<const char*,std::set<const char*> >(newFlowBindingEntry->getFlowSourceAddress(),mySrcAdressSet) );

    std::set<const char*> myDestAdressSet;
    myDestAdressSet.insert(newFlowBindingEntry->getDestAddress());
    destAdresses.insert ( std::pair<const char*,std::set<const char*> >(newFlowBindingEntry->getFlowSourceAddress(),myDestAdressSet) );


}

//check if an entry already exists:
bool FlowBindingTable::entryAlreadyExistsInTable(const char* flowSourceAdress){
    const bool srcPortFound = this->srcPorts.find(flowSourceAdress) != srcPorts.end();
    const bool destPortFound = this->destPorts.find(flowSourceAdress) != destPorts.end();
    const bool srcAddressFound = this->srcAdresses.find(flowSourceAdress) != srcAdresses.end();
    const bool destAddressFound = this->destAdresses.find(flowSourceAdress) != destAdresses.end();

    return (srcPortFound && destPortFound && srcAddressFound && destAddressFound);
}

//it has to be checked first if the entry really exist by calling the above method first !
FlowBindingEntry* FlowBindingTable::getFlowBindingEntryFromTable(const char* flowSourceAdress){


//    const bool srcPortFound = this->srcPorts.find(flowSourceAdress) != srcPorts.end();

    if(entryAlreadyExistsInTable(flowSourceAdress)){

        std::map<const char*,int>::iterator srcPortIterator =  srcPorts.find(flowSourceAdress);
        int srcPort = srcPortIterator->second;

        std::map<const char*,int>::iterator destPortIterator =  destPorts.find(flowSourceAdress);
        int destPort = destPortIterator->second;

        std::map<const char*,std::set<const char*> >::iterator srcAddresstIterator =  srcAdresses.find(flowSourceAdress);
        std::set<const char*> srcAddressesOfTheNode = srcAddresstIterator->second;
        std::set<const char*> ::iterator srcAddressesOfTheNodeIterator = srcAddressesOfTheNode.begin();//use the first IP Address found
        const char* usedSourceAddress = *srcAddressesOfTheNodeIterator;

        std::map<const char*,std::set<const char*> >::iterator destAddresstIterator =  destAdresses.find(flowSourceAdress);
        std::set<const char*> destAddressesOfTheNode = destAddresstIterator->second;
        std::set<const char*> ::iterator destAddressesOfTheNodeIterator = destAddressesOfTheNode.begin();//use the first IP Address found
        const char* usedDestAddress = *destAddressesOfTheNodeIterator;



        cout<<"FlowBinding entry was found"<<endl;
        cout<<"Found Source Port: "<<srcPort<<"\n  Dest Port:"<<destPort<<"\n  Source Address: "<<usedSourceAddress<<"\n Dest Address: "<<usedDestAddress<<"\n for Key:"<<srcPortIterator->first<<endl;


        return new FlowBindingEntry(true,srcPort,destPort,usedSourceAddress,usedDestAddress);
    }
    else{
        return new FlowBindingEntry(false,0,0,"none","none");
    }
}
