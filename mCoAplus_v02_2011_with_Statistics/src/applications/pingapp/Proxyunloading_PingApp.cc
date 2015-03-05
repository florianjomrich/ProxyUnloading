//
// Copyright (C) 2001, 2003, 2004 Johnny Lai, Monash University, Melbourne, Australia
// Copyright (C) 2005 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//

#include <limits.h>
#include <stdlib.h>
#include <iostream>

#include "IPAddressResolver.h"
#include "PingApp.h"
#include "PingPayload_m.h"
#include "IPControlInfo.h"
#include "IPv6ControlInfo.h"

using std::cout;

class Proxyunloading_PingApp : public PingApp{

    void initialize()
    {
        PingApp::initialize();
        cout<< "ProxyUnloading_IP: " << par("homeAgentAddress").stringValue()[0];
    }

};


