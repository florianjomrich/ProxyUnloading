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

#include <BindingUpdateInformationtoAPPmessageCN.h>



BindingUpdateInformation_to_APP_message_CN::BindingUpdateInformation_to_APP_message_CN() {
    // TODO Auto-generated constructor stub

}

BindingUpdateInformation_to_APP_message_CN::~BindingUpdateInformation_to_APP_message_CN() {
    // TODO Auto-generated destructor stub
}


 void BindingUpdateInformation_to_APP_message_CN::setHomeAddress( IPv6Address& hoA){
     this->HoA = hoA;
 }
IPv6Address& BindingUpdateInformation_to_APP_message_CN::getHomeAddress(){
    return this->HoA;
}

void BindingUpdateInformation_to_APP_message_CN::setCareOfAddress( IPv6Address& coA){
     this->CoA = coA;
 }
IPv6Address& BindingUpdateInformation_to_APP_message_CN::getCareOfAddress(){
    return this->CoA;
}

void BindingUpdateInformation_to_APP_message_CN::setDestinationAddress( IPv6Address& destAddress){
     this->DestAddress = destAddress;
 }
IPv6Address& BindingUpdateInformation_to_APP_message_CN::getDestinationAddress(){
    return this->DestAddress;
}
