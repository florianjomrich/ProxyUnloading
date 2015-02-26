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

package proxyunloading.simulations;

import inet.nodes.xmipv6.CorrespondentNode6;// da ich IPv6 verwenden möchte und - IP/TCP-Pakete - daher reicht der EtherHost nicht aus !!! siehe: http://stackoverflow.com/questions/14454548/how-to-use-etherhost-in-omnet
import inet.nodes.inet.StandardHostWithDLDuplicatesGenerator;
import inet.nodes.wireless.WirelessAPWithEthMCoA;
import inet.nodes.xmipv6.WirelessHost6Multi;
import inet.world.ChannelControlExtended;
import inet.nodes.xmipv6.HomeAgent6;
import inet.nodes.ipv6.Router6;
import inet.networklayer.autorouting.MCoANetConf6;
import inet.linklayer.ethernet.EtherHub;

//import inet.nodes.ethernet.Eth100M;

channel ethernetline extends ned.DatarateChannel
{
    parameters:
        //delay = 0.1us;
        delay = 10ms;
}


network ProxyUnloading
{
    @display("bgb=946,437");
    submodules:
        youtube: CorrespondentNode6 {
            @display("p=236,49");
        }
        spotify: CorrespondentNode6 {
            @display("p=509,59");
        }
        roadSideUnit_A: WirelessAPWithEthMCoA {
            @display("p=275,248");
        }
        car1: WirelessHost6Multi {
            @display("p=519,383");
        }
        //Kanal Kontrolle -
        channelControl: ChannelControlExtended {
            @display("p=67,370");
        }
        //Netzwerk-Konfigurator - dient laut INET-Manual dafür IP Adressen an Hosts und Router zu vergeben und statisches Routing zu ermöglichen
        configurator: MCoANetConf6 {
            parameters:
                @display("p=176,370");
        }
        proxy_Server_HA: HomeAgent6 {
            parameters:
                @display("p=436,153;i=abstract/router");
        }
        roadSideUnit_B: WirelessAPWithEthMCoA {
            @display("p=493,248");
        }
    connections:

        proxy_Server_HA.ethOut++ --> ethernetline --> roadSideUnit_A.ethg$i++;//++ bedeutet, das immer der nächste Port in der Hierarchie genommen wird
        proxy_Server_HA.ethOut++ --> ethernetline --> roadSideUnit_B.ethg$i++;// mit [0],[1] kann man die Ports aber auch direkt addressieren/spezifizieren
        roadSideUnit_A.ethg$o++ --> ethernetline --> proxy_Server_HA.ethIn++; //da es sich hierbei um einen IO-Port handelt muss man mit $o bzw. $i den korrekten Port ansprechen
        roadSideUnit_B.ethg$o++ --> ethernetline --> proxy_Server_HA.ethIn++;

        proxy_Server_HA.ethOut++ --> ethernetline --> spotify.ethIn++;
        proxy_Server_HA.ethOut++ --> ethernetline --> youtube.ethIn++;
        spotify.ethOut++ --> ethernetline --> proxy_Server_HA.ethIn++;
        youtube.ethOut++ --> ethernetline --> proxy_Server_HA.ethIn++;


}
