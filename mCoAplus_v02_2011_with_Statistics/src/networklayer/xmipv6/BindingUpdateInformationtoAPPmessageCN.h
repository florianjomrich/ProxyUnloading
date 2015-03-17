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

#ifndef BINDINGUPDATEINFORMATIONTOAPPMESSAGECN_H_
#define BINDINGUPDATEINFORMATIONTOAPPMESSAGECN_H_

#include <cmessage.h>
#include <IPv6Address.h>

class BindingUpdateInformation_to_APP_message_CN: public cMessage {



public:
    IPv6Address HoA;
    IPv6Address CoA;
    IPv6Address DestAddress;

    BindingUpdateInformation_to_APP_message_CN();
    virtual ~BindingUpdateInformation_to_APP_message_CN();
    virtual void setHomeAddress( IPv6Address& hoA);
    virtual  IPv6Address& getHomeAddress();
    virtual void setCareOfAddress( IPv6Address& coA);
    virtual  IPv6Address& getCareOfAddress();
    virtual void setDestinationAddress( IPv6Address& destAddress);
    virtual  IPv6Address& getDestinationAddress();
};

#endif /* BINDINGUPDATEINFORMATIONTOAPPMESSAGECN_H_ */
