

package com.ipmessenger;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;

class splashScreen extends JFrame {
    static JProgressBar progressBar = new JProgressBar();

    static int count = 1, TIMER_PAUSE = 30, PROGBAR_MAX = 100;
    static Timer progressBarTimer;
    private  int status;
    private  BufferedImage image;

    public int getStatus() {
        return status;
    }

    ActionListener al = new ActionListener() {
        @Override
        public void actionPerformed(java.awt.event.ActionEvent evt) {
            progressBar.setValue(count);
            if (PROGBAR_MAX == count) {
                progressBarTimer.stop();
                splashScreen.this.setVisible(false);
                status=0;

            }
            count++;
        }
    };

    public splashScreen() {
        progressBar.setString("Loading...");
        setSize(new Dimension(700,400));
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        setLocation((dim.width-getSize().width)/2,(dim.height-getSize().height)/2);

        Container container = getContentPane();
        ImageIcon ic = new ImageIcon("u4.png");
        setUndecorated(true);
        Image im = ic.getImage();
        try{

            image = ImageIO.read(new File("splash.jpg"));
        }catch (Exception e){

        }
        JPanel panel = new JPanel(){

            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);

                g.drawImage(image,0,0,getWidth(),getHeight(),null);
            }
        };
//        panel.setBackground(Color.BLUE);

        container.add(panel);

//        JLabel label = new JLabel("Ip Messenger");
//        label.setIcon(ic);
//        label.setFont(new Font("Verdana", Font.BOLD, 26));
//        panel.add(label);
//
        progressBar.setMaximum(PROGBAR_MAX);
        container.add(progressBar, BorderLayout.SOUTH);
//        pack();
        setVisible(true);
        status=1;
        startProgressBar();
    }
    private void startProgressBar() {
        progressBarTimer = new Timer(TIMER_PAUSE, al);
        progressBarTimer.start();
    }

}
//
//import javax.swing.*;
//import java.awt.*;
//
//public class splashScreen extends JFrame {
//
//    public splashScreen()
//    {
//        setSize(new Dimension(600,300));
//        setVisible(true);
//
//
//        ImageIcon ic = new ImageIcon("splash.jpg");
//        Image im = ic.getImage();
//        JPanel panel = new JPanel(new FlowLayout());
//        add(panel);
//
//    }
//
//}
