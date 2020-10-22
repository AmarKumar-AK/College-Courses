package com.ipmessenger;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
public class ip extends Thread{
    public void run(){
        int timeout=100;
        String subnet="192.168";
        for (int i=0;i<255;i++){
            for(int j=0; j<255; j++)
            {
                String host = subnet + "." + i + "." + j;
                try {
                    if (InetAddress.getByName(host).isReachable(timeout)) {
                        System.out.println(host + " is reachable");
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
