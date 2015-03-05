// 
//



import inet.linklayer.ethernet.EtherHub;
import inet.nodes.ipv6.Router6;
import inet.nodes.wireless.WirelessAPWithEthMCoA;
import inet.nodes.xmipv6.CorrespondentNode6;
import inet.nodes.xmipv6.HomeAgent6;
import inet.nodes.xmipv6.WirelessHost6Multi;
import inet.world.ChannelControlExtended;
import inet.networklayer.autorouting.MCoANetConf6;
import inet.networklayer.ipv6.IPv6;
import inet.nodes.ipv6.StandardHost6;
import inet.nodes.xmipv6.MobileNode6;
import inet.world.ScenarioManager;


package testmcoa_v2_2011.simulations.testMCoAv2;

channel fiberline extends ned.DatarateChannel
{
    parameters:
        delay = 1us;
        datarate = 512*1000000;
}

channel ethernetline extends ned.DatarateChannel
{
    parameters:
        //delay = 0.1us;
        delay = 10ms;
}

channel ethernetlineR1 extends ned.DatarateChannel
{
    parameters:
        //delay = 0.1us;
        delay = 10ms;

}

channel internetline extends ned.DatarateChannel
{
    parameters:
        //delay = 0.1us;
        delay = 20ms;
}

channel internetline2 extends ned.DatarateChannel
{
    parameters:
        //delay = 0.1us;
        delay = 40ms;
}

network VoIPMCoAMulti
{
    parameters:
        double total_mn;
        double total_cn;
        double playgroundSizeX;
        double playgroundSizeY;

        @display("bgb=799,559");
    submodules:
        //configurator: FlatNetworkConfigurator6 {
        configurator: MCoANetConf6 {
            parameters:
                @display("p=763,53");
        }
        channelcontrol: ChannelControlExtended {
            parameters:
                playgroundSizeX = playgroundSizeX;
                playgroundSizeY = playgroundSizeY;
                //numChannels = 5;
                @display("p=753,123");
        }
        Ra: Router6 {
            parameters:
                @display("p=378,330");
        }
        CN[total_cn]: CorrespondentNode6 {
            @display("p=239,488");
        }
        hub: EtherHub {
            parameters:
                @display("p=329,461;i=device/hub_s");
        }
        HA: HomeAgent6 {
            parameters:
                @display("p=149,228;i=abstract/router");
        }
        AP_HA: WirelessAPWithEthMCoA {
            @display("p=149,166;i=device/accesspoint_s");
            mgmtType = default("Ieee80211MgmtAP");

        }
        MN[total_mn]: WirelessHost6Multi {
            parameters:
                @display("p=270,123");
                //numRadios=3;

        }
        R1: Router6 {
            parameters:
                @display("p=378,244");
        }
        AP_1: WirelessAPWithEthMCoA {
            parameters:
                @display("p=445,166;i=device/accesspoint_s");
                mgmtType = default("Ieee80211MgmtAP");
        }
        ScenMana: ScenarioManager {
            @display("p=610,70");
        }
        AP_2: WirelessAPWithEthMCoA {
            parameters:
                @display("p=683,172;i=device/accesspoint_s");
                mgmtType = default("Ieee80211MgmtAP");
        }
        Rb: Router6 {
            parameters:
                @display("p=378,419");
        }
    connections allowunconnected:

                         //Home_Agent.ethOut++ --> ethernetline --> R_1.ethIn++;
                         //Home_Agent.ethIn++ <-- ethernetline <-- R_1.ethOut++;

        for i=0..total_cn-1 {
            CN[i].ethOut++ --> ethernetline --> hub.ethg$i++;
            CN[i].ethIn++ <-- ethernetline <-- hub.ethg$o++;
        }

        HA.ethOut++ --> ethernetline --> Ra.ethg$i++;
        HA.ethIn++ <-- ethernetline <-- Ra.ethg$o++;


        AP_HA.ethg$o++ --> ethernetline --> HA.ethIn++;
        AP_HA.ethg$i++ <-- ethernetline <-- HA.ethOut++;


        R1.ethg++ <--> ethernetline <--> Ra.ethg++;
        AP_1.ethg++ <--> ethernetline <--> R1.ethg++;
        R1.ethg++ <--> ethernetline <--> AP_2.ethg++;

        Rb.ethg++ <--> internetline <--> Ra.ethg++;
        hub.ethg++ <--> ethernetline <--> Rb.ethg++;


}
