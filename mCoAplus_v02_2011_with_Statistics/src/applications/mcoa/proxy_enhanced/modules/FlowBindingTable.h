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

#ifndef FLOWBINDINGTABLE_H_
#define FLOWBINDINGTABLE_H_

#include <csimplemodule.h>
#include <omnetpp.h>
#include <map>
#include <set>
#include <FlowBindingEntry.h>
#include <RequetConnectionToLegacyServer_m.h>
#include <ACK_RequestConnectionToLegacyServer_m.h>
// alternative #include <string.h>

class FlowBindingTable: public cSimpleModule {
public:

    std::map<const char*, int> srcPorts; //use the flow-source-adress-string as Key for every Map
    std::map<const char*, int> destPorts;
    std::map<const char*, std::set<const char*> > srcAdresses;
    std::map<const char*, std::set<const char*> > destAdresses;


    FlowBindingTable();
    virtual ~FlowBindingTable();
    virtual void handleMessage(cMessage *msg);
    virtual void insertNewFlowBindingEntry(RequetConnectionToLegacyServer *newFlowBindingEntry);
    virtual void insertNewFlowBindingEntry(ACK_RequestConnectionToLegacyServer *newFlowBindingEntry);
    virtual FlowBindingEntry* getFlowBindingEntryFromTable(const char* flowSourceAdress);
    virtual bool entryAlreadyExistsInTable(const char* flowSourceAdress);
};

#endif /* FLOWBINDINGTABLE_H_ */
