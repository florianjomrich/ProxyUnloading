// Copyright (C) 2007 Faqir Zarrar Yousaf
// Communication Networks Institute, University of Dortmund
// faqir.yousaf@uni-dortmund.de
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

//
// IPv6 router Configured to operate as a Home Agent in a network supporting MIPv6.
//

package inet.nodes.xmipv6;

import inet.applications.pingapp.PingApp;
import inet.applications.tcpapp.TCPApp;
import inet.applications.udpapp.UDPApp;
import inet.applications.mcoa.proxy_enhanced.control.Proxy_Unloading_Control_App;
import inet.applications.mcoa.proxy_enhanced.modules.FlowBindingTable;
import inet.base.NotificationBoard;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.ipv6.RoutingTable6;
import inet.networklayer.xmipv6.BindingCache;
import inet.transport.tcp.TCP;
import inet.transport.udp.UDP;


module Proxy_Enhanced_HomeAgent6
{
    parameters:
        double numTcpApps;
        double numUdpApps;
        string tcpAppType;
        string udpAppType;
        @node();
        @display("bgb=893,393");
    gates:
           //in: in[];
           //out: out[];
        input ethIn[];
        output ethOut[];

        inout from_to_MN[];
        inout from_to_CN[];

    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=60,60;i=block/control");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=170,60;i=block/table");
        }
        bindingCache: BindingCache {
            parameters:
                @display("p=55,124;i=old/harddisk");
        }
        flowBindingTable: FlowBindingTable {
            parameters:
                @display("p=60,209;i=old/floppy1");
        }
        routingTable6: RoutingTable6 {
            parameters:
                isRouter = true;
                @display("p=263,67;i=block/table2");
        }
        tcpApp[numTcpApps]: <tcpAppType> like TCPApp {
            parameters:
                @display("p=524,53;i=block/app");
        }
        tcp: TCP {
            parameters:
                @display("p=510,146;i=block/wheelbarrow");
        }
        udpApp[numUdpApps]: <udpAppType> like UDPApp {
            parameters:
                @display("i=block/app;p=680,53");
        }
        udp: UDP {
            parameters:
                @display("p=660,146;i=block/transport");
        }
        proxyUnloadingControlApp: Proxy_Unloading_Control_App {
            parameters:
                isMN = false; //is Mobile Node
                isHA = true; //is Home Agent
                isCN = false;//is Correspondent Node
                @display("p=822,156;i=block/wheelbarrow");
        }
        pingApp: PingApp {
            parameters:
                @display("i=block/app;p=594,257");
        }
        networkLayer: Proxy_Unloading_MobileIPLayer6 {
            parameters:
                isMN = false; //is Mobile Node
                isHA = true; //is Home Agent
                isCN = false;//is Correspondent Node
                @display("p=594,177;i=block/fork;q=queue");
            gates:
                ifIn[sizeof(out)+sizeof(ethOut)];
                ifOut[sizeof(out)+sizeof(ethOut)];
        }
        eth[sizeof(ethOut)]: EthernetInterface {
            parameters:
                @display("p=357,257,row,110;q=l2queue;i=block/ifcard");
        }
    connections allowunconnected:
        for i=0..numTcpApps-1 {
            tcpApp[i].tcpOut --> tcp.appIn++;
            tcpApp[i].tcpIn <-- tcp.appOut++;
        }

        tcp.ipv6Out --> networkLayer.tcpIn;
        tcp.ipv6In <-- networkLayer.TCPOut;

        for i=0..numUdpApps-1 {
            udpApp[i].udpOut --> udp.appIn++;
            udpApp[i].udpIn <-- udp.appOut++;
        }

        udp.ipv6Out --> networkLayer.udpIn;
        udp.ipv6In <-- networkLayer.udpOut;

        networkLayer.pingOut --> pingApp.pingv6In;
        networkLayer.pingIn <-- pingApp.pingv6Out;

                                                   // connections to network outside
                                                   // for i=0..sizeof(out)-1 do
                                                   //   in[i] --> ppp[i].physIn;
                                                   // out[i] <-- ppp[i].physOut;
                                                   //ppp[i].netwOut --> networkLayer.ifIn[i];
                                                   //ppp[i].netwIn <-- networkLayer.ifOut[i];
                                                   //endfor;

        for i=0..sizeof(ethOut)-1 {
            ethIn[i] --> eth[i].phys$i;
            ethOut[i] <-- eth[i].phys$o;
            eth[i].netwOut --> networkLayer.ifIn[sizeof(out)+i];
            eth[i].netwIn <-- networkLayer.ifOut[sizeof(out)+i];
        }

        //PROXY EXTENSION - FOR CONTROLL MESSAGES FJ
        proxyUnloadingControlApp.udpOut --> udp.appIn++;
        proxyUnloadingControlApp.udpIn <-- udp.appOut++;
        proxyUnloadingControlApp.uDPControllAppConnection <--> networkLayer.uDPControllAppConnection;
}

