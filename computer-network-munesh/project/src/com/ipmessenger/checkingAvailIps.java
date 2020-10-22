package com.ipmessenger;

import javax.swing.*;
import java.util.ArrayList;

public class checkingAvailIps extends Thread {

    private JList<String> list;
    private DefaultListModel ips;
    private String subnet;
    private int status;
    private ArrayList<String> myips;

    public checkingAvailIps(JList<String> list, DefaultListModel ips, String subnet, ArrayList<String> myips) {
        this.list = list;
        this.ips = ips;
        this.subnet = subnet;
        this.myips=myips;
    }

    public int getStatus() {
        return status;
    }

    @Override
    public void run() {
        super.run();
        status=1;
        checkingByPing [][]c=new checkingByPing[256][256];
        for (int i=40;i<45;i++) {
            for (int j = 0; j < 256; j++) {
                try {
//                    if(list.getSelectedValue().equals())
                    c[i][j] = new checkingByPing(subnet,i,j,list,ips,myips);
                    c[i][j].start();
                }catch (Exception e1){
                    try {
                        sleep(7000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    status=0;
                }
            }
        }

        for(int i=40; i<45; i++)
        {
            for(int j=0; j<256; j++)
            {
                try {
                    c[i][j].join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
        System.out.println("hhhhmmmmmmmmmmm...........");
        status=0;
    }
}
