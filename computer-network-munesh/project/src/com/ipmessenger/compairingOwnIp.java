package com.ipmessenger;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Iterator;

public class compairingOwnIp {
    ArrayList<String> myips = new ArrayList<>();

    public ArrayList<String> getMyips() {
        return myips;
    }

    public compairingOwnIp()
    {

        try
        {
            Enumeration<NetworkInterface> n = NetworkInterface.getNetworkInterfaces();
            for(;n.hasMoreElements();)
            {
                NetworkInterface e = n.nextElement();
                Enumeration<InetAddress> a = e.getInetAddresses();
//                System.out.println(e.getName()+".......");
                while(a.hasMoreElements())
                {
                    InetAddress addr = a.nextElement();
                    if(addr.getHostAddress().length()<=15 )
                        myips.add(addr.getHostAddress());
                }
            }
        }
        catch (Exception e )
        {

        }

    }
}
