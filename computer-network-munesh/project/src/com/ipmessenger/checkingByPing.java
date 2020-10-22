package com.ipmessenger;

import javax.swing.*;
import java.lang.reflect.Array;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.ArrayList;

public class checkingByPing extends Thread {

    private String subnet;
    private int i,j;
    private JList<String> list ;
    private DefaultListModel ips;
    private ArrayList<String> myips;

    public checkingByPing(String subnet, int i, int j, JList list, DefaultListModel ips,ArrayList<String> myips) {
        this.subnet = subnet;
        this.i = i;
        this.j = j;
        this.list = list;
        this.ips = ips;
        this.myips =myips;
        list.setModel(ips);
    }



    @Override
    public void run() {
        String host="";
        super.run();
        try {

            host = subnet + "." + i + "." + j;

//            compairingOwnIp compairingOwnIp = new compairingOwnIp();
//            ArrayList<String> myips = compairingOwnIp.getMyips();
            int flag =1;
            for(int i=0;i<myips.size();i++)
            {
                if(myips.get(i).equals(host))
                {
                    flag =0;
                    break;
                }
            }
            if(flag==1)
            {
                Socket s = new Socket();
                s.connect(new InetSocketAddress(host,5000),5000);
                int flag1 =1;
                System.out.println(host+"....................ava");
                for(int i=0;i<ips.size();i++)
                {
                    if(ips.get(i).equals(host))
                    {
                        flag1 =0;
                        break;
                    }
                }
                if(flag1==1)
                {

                    ips.addElement(host);
                    for(int i=0;i<ips.size();i++)
                    {
                        System.out.println("Ip from ips: "+ips.get(i));
                    }
                }
            }


        }
        catch (Exception e)
        {
            System.out.println(host+"fail");
        }
    }
}
