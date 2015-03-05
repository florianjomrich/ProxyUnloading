/**
 * Copyright (C) 2010
 * Bruno Sousa
 * Laboratory and Communications and Telematics (LCT), University of Coimbra, Portugal

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */


#ifndef IPV6PREFADR_H_
#define IPV6PREFADR_H_

#include <omnetpp.h>
#include "INETDefs.h"
#include "IPv6Address.h"


class IPv6PrefAdr : public cPolymorphic
{
protected:
    IPv6Address prefAdr;
    uint preferencePriority;

public:
    IPv6PrefAdr();
    IPv6PrefAdr(IPv6Address _en, uint prio);

    virtual ~IPv6PrefAdr();

    IPv6Address getPrefAdr() const;
    uint getPreferencePriority() const;

    void setPrefAdr(IPv6Address prefAdr);

    void setPreferencePriority(uint preferencePriority);

};

#endif /* IPV6PREFADR_H_ */
