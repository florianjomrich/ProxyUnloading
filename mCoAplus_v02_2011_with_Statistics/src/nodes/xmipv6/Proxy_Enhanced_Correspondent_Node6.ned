//
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

// Same as StandardHost6.ned except with the new parameter isMobileNode = true/false
// & isHomeAgent = true/false & isProxy = false (for FMIPv6)

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



//
// An IPv6 host with MIPv6 support and contains a Binding Cache which gets updated with every BU received.
//
module Proxy_Enhanced_Correspondent_Node6
{
    parameters:
        @node();
        double numTcpApps;
        double numUdpApps;
        string tcpAppType;
        string udpAppType;
        @display("bgb=895,397;i=device/pc2");
    gates:
           //in: in[];
           //out: out[];
        input ethIn[];
        output ethOut[];

        inout from_to_HA;
        inout from_to_MN;
    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=60,70;i=block/control");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=60,150;i=block/table");
        }
        bindingCache: BindingCache {
            parameters:
                @display("p=75,293;i=old/harddisk");
        }
        flowBindingTable: FlowBindingTable {
            parameters:
                @display("p=392,149;i=old/floppy1");
        }
        routingTable6: RoutingTable6 {
            parameters:
                isRouter = false;
                @display("p=71,219;i=block/table2");
        }
        tcpApp[numTcpApps]: <tcpAppType> like TCPApp {
            parameters:
                @display("p=179,75;i=block/app");
        }
        tcp: TCP {
            parameters:
                @display("p=218,219;i=block/wheelbarrow");
        }
        udpApp[numUdpApps]: <udpAppType> like UDPApp {
            parameters:
                @display("i=block/app;p=728,75");
        }
        udp: UDP {
            parameters:
                @display("p=728,170;i=block/transport");
        }
        proxyUnloadingControlApp: Proxy_Unloading_Control_App {
            parameters:
                isMN = false; //is Mobile Node
                isHA = false; //is Home Agent
                isCN = true;//is Correspondent Node
                @display("p=530,162;i=block/wheelbarrow");
        }
        pingApp: PingApp {
            parameters:
                @display("i=block/app;p=749,286");
        }
        networkLayer: Proxy_Unloading_MobileIPLayer6 {
            parameters:
                isMN = false; //is Mobile Node
                isHA = false; //is Home Agent
                isCN = true;//is Correspondent Node
                @display("p=648,247;i=block/fork;q=queue");
            gates:
                ifIn[sizeof(in)+sizeof(ethIn)];
                ifOut[sizeof(out)+sizeof(ethOut)];
        }
        eth[sizeof(ethOut)]: EthernetInterface {
            parameters:
                @display("p=648,342,row,90;q=txQueue;i=block/ifcard");
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


        //PROXY ENHANCED
        proxyUnloadingControlApp.APP_proxy_Enhanced_Control_Channel <--> networkLayer.NETWORK_LAYER_proxy_Enhanced_Control_Channel;
        proxyUnloadingControlApp.udpOut --> udp.appIn++;
        proxyUnloadingControlApp.udpIn <-- udp.appOut++;
        proxyUnloadingControlApp.uDPControllAppConnection <--> networkLayer.uDPControllAppConnection;
}

