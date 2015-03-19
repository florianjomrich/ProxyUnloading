//
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


import inet.applications.udpapp.UDPApp;
import inet.applications.mcoa.udpbase.MCoAUDPBase;
package inet.applications.mcoa.proxy_enhanced.control;

//
// Video streaming client.
//
// @see UDPVideoStreamSvr
//
simple Proxy_Unloading_Control_App like MCoAUDPBase
{
    parameters:
        
        //string serverAddress;
        int destPort;
        //double startTime @unit("s") = default(1s);
        
        //From interface
        int localPort;
        string useMode;// = default("SINGLERANDOM"); //Should have values in MCoADefs.h
    	bool useMCoA ;// to use MCoA?
    	string destAddresses = default(""); // list of \IP addresses, separated by spaces
    	bool isDestiny = default(true); //If it is destiny (ony replies to messages).
    	
    	//FOR PROXY_UNLOADING FJ
    	double startTime = default(10);//start Proxying Process at StartTime
    	bool isMN; //is Mobile Node
        bool isHA; //is Home Agent
        bool isCN;//is Correspondent Node
        bool isCapableCN;//to set whether the current CN is capable of dealing with the protocol or not
    	
    gates:
        input udpIn;
        output udpOut;
        inout APP_proxy_Enhanced_Control_Channel;
        input fromBindingUpdateList;
        inout uDPControllAppConnection;
        inout bindingUpdateChannelToProxyControlApp;
       
}

