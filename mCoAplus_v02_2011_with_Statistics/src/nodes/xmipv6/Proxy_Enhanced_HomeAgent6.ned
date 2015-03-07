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
import inet.applications.mcoa.proxy_enhanced.Proxy_Enhanced_MCoAVideoProxy;
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
                @display("p=150,60;i=block/table");
        }
        bindingCache: BindingCache {
            parameters:
                @display("p=55,124;i=old/harddisk");
        }
        routingTable6: RoutingTable6 {
            parameters:
                isRouter = true;
                @display("p=257,36;i=block/table2");
        }
        tcpApp[numTcpApps]: <tcpAppType> like TCPApp {
            parameters:
                @display("p=218,99;i=block/app");
        }
        tcp: TCP {
            parameters:
                @display("p=187,170;i=block/wheelbarrow");
        }
        udpApp[numUdpApps]: Proxy_Enhanced_MCoAVideoProxy {
            parameters:
                @display("i=block/app;p=343,53");
        }
        udp: UDP {
            parameters:
                @display("p=323,146;i=block/transport");
        }
        pingApp: PingApp {
            parameters:
                @display("i=block/app;p=335,248");
        }
        networkLayer: Proxy_Enhanced_MobileIPLayer6_For_Home_Agent {
            parameters:
                isMN = false; //is Mobile Node
                isHA = true; //is Home Agent
                @display("p=257,177;i=block/fork;q=queue");
            gates:
                ifIn[sizeof(out)+sizeof(ethOut)];
                ifOut[sizeof(out)+sizeof(ethOut)];
        }
        eth[sizeof(ethOut)]: EthernetInterface {
            parameters:
                @display("p=145,257,row,110;q=l2queue;i=block/ifcard");
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
        for i=0..sizeof(from_to_MN)-1 {
            from_to_MN[i] <--> networkLayer.NETWORK_LAYER_HA_TO_MN++;
        }
        for k=0..sizeof(from_to_CN)-1 {
            from_to_CN[k] <--> networkLayer.NETWORK_LAYER_HA_TO_CN++;
        }
        
         for k=0..numUdpApps-1{
        udpApp[k].APP_proxy_Enhanced_Control_Channel_HA     <--> networkLayer.NETWORK_LAYER_proxy_Enhanced_Control_Channel_HA++;
        }
}

