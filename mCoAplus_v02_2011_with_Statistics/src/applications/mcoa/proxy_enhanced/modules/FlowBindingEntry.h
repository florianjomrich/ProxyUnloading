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

#ifndef FLOWBINDINGENTRY_H_
#define FLOWBINDINGENTRY_H_

class FlowBindingEntry {
public:
    bool isValidEntry;
    int srcPort;
    int destPort;
    const char* srcAddress;
    const char* destAddress;

    FlowBindingEntry();
    FlowBindingEntry(bool isValidEntry,int srcPort, int destPort,const char* srcAddress,const char* destAddress);
    virtual ~FlowBindingEntry();

    const char* getDestAddress() const {
        return destAddress;
    }

    void setDestAddress(char* destAddress) {
        this->destAddress = destAddress;
    }

    int getDestPort() const {
        return destPort;
    }

    void setDestPort(int destPort) {
        this->destPort = destPort;
    }

    bool isIsValidEntry() const {
        return isValidEntry;
    }

    void setIsValidEntry(bool isValidEntry) {
        this->isValidEntry = isValidEntry;
    }

    const char* getSrcAddress() const {
        return srcAddress;
    }

    void setSrcAddress(const char* srcAddress) {
        this->srcAddress = srcAddress;
    }

    int getSrcPort() const {
        return srcPort;
    }

    void setSrcPort(int srcPort) {
        this->srcPort = srcPort;
    }
};

#endif /* FLOWBINDINGENTRY_H_ */
