package com.ipmessenger;

import javax.swing.*;

public class progressBar extends Thread {

    private JProgressBar pb;
    private boolean stop;
    private int percent;

    public progressBar() {
        JFrame frame = new JFrame("Sending");
        pb = new JProgressBar();
        JPanel p = new JPanel();
        p.add(pb);
        frame.add(p);
        stop=true;
        frame.setSize(200,100);
        frame.setVisible(true);
    }

    @Override
    public void run() {
        int i=0;
        while(stop){
            pb.setValue(i);
            i=percent;
            try{Thread.sleep(150);}catch(Exception e){}
        }



    }

    public void setStop(boolean stop) {
        this.stop = stop;
    }

    public void setPercent(int percent) {
        this.percent = percent;
    }
}
