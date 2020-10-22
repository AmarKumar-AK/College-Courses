package com.ipmessenger;

import javax.swing.*;
import javax.swing.text.*;
import javax.swing.text.html.HTMLDocument;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.concurrent.TimeoutException;

public class clientConnect extends Thread {

    // initialize socket and input output streams
    private Socket socket            = null;
//    private DataInputStream input   = null;
    private DataOutputStream out     = null;
    private String address = null;
    private int port = 0;
    private JTextArea taMsgSend;
    private JEditorPane epHistory;
    private JButton sendButton;
    private DataInputStream In=null;
    private  JButton btnMediaButton;
    private  JPanel panel1;
    private long pid;
    private  JFileChooser fc=null;
    private JLabel labelName;


    // constructor to put ip address and port
    public clientConnect(String adr, int prt,JTextArea taMsgSend,JEditorPane epHistory,JButton sendButton,JButton btnMediaButton,JPanel panel1,JLabel labelName) {
        address = adr;
        port = prt;
        this.taMsgSend=taMsgSend;
        this.sendButton=sendButton;
        this.epHistory=epHistory;
        this.btnMediaButton=btnMediaButton;
        this.panel1=panel1;
        this.labelName=labelName;

    }

    public Socket getSocket() {
        return socket;
    }
    public DataOutputStream getOut() {
        return out;
    }

    public long getPid() {
        return pid;
    }

    public void run() {// establish a connection
//        StyledDocument doc = taHistory.getStyledDocument();
//
//        SimpleAttributeSet left = new SimpleAttributeSet();
//        StyleConstants.setBackground(left, Color.YELLOW);
//        StyleConstants.setForeground(left, Color.RED);
//        StyleConstants.setAlignment(left, StyleConstants.ALIGN_LEFT);
//        StyleConstants.setFontSize(left,24);
//        StyleConstants.setSpaceAbove(left,20);
//
//
//
//        SimpleAttributeSet right = new SimpleAttributeSet();
//        StyleConstants.setBackground(right, Color.GRAY);
//        StyleConstants.setForeground(right, Color.BLUE);
//        StyleConstants.setAlignment(right, StyleConstants.ALIGN_RIGHT);
//        StyleConstants.setFontSize(right,24);
//        StyleConstants.setSpaceAbove(right,20);

        try
        {
            pid = Thread.currentThread().getId();
            System.out.println("first time\n");
            socket = new Socket();
            socket.connect(new InetSocketAddress(address, port), 1000);
            System.out.println("CCCsocket = "+socket);
            System.out.println("Connected"+Thread.currentThread().getId());


            System.out.println("Printing the  IP List");
            File file = new File("database/ip.txt");
            file.setWritable(true,false);
            FileWriter fr= new FileWriter(file, true);
            BufferedWriter br = new BufferedWriter(fr);

            br.write(socket.getInetAddress().getHostAddress()+"\n");

            br.close();
            fr.close();
            file.setReadOnly();

            try {
                out    = new DataOutputStream(socket.getOutputStream());
                In = new DataInputStream(socket.getInputStream());

            }
            catch(IOException e2)
            {}

            sendButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent actionEvent)  {
                    String msg=taMsgSend.getText();
                    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM HH:mm");
                    LocalDateTime now = LocalDateTime.now();
                    if(!msg.equals(null) && !msg.equals("") &&( fc==null || fc.getSelectedFile()==null))
                    {
                        taMsgSend.setText("");
                        System.out.println("send b clicked");

                        String filename=socket.getInetAddress().getHostName();
                        System.out.println("pid:"+Thread.currentThread().getId());
                        try {
                            out.writeUTF(msg);
                            String ack;
                            ack=In.readUTF();
                            if(ack.equals("ackOK") && !msg.equals(""))
                            {
                                String newmsg = msg;
                                newmsg=newmsg.trim();
                                try
                                {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                    HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                    Element elem = doc.getElement("body");
                                    String line = "<div class='div2'>"+newmsg+"</div>";
                                    System.out.println("line: "+line);
                                    String htmlText = String.format("<p>%s</p>", line);
                                    try {
                                        doc.insertBeforeEnd(elem, htmlText);
                                    } catch (BadLocationException | IOException ex) {
                                        ex.printStackTrace();
                                    }

                                }
                                catch (Exception e)
                                {

                                }
//                                taHistory.setText(taHistory.getText()+"[You @ "+dtf.format(now)+"]: "+msg+"\n");
                                System.out.println("filename"+filename.replace('.','_'));
                                File file=new File("database/"+filename.replace(".","_")+".txt");
                                file.setWritable(true,false);
                                FileWriter fr=new FileWriter(file,true);
                                BufferedWriter br=new BufferedWriter(fr);
                                br.write("[You @ "+dtf.format(now)+"]"+msg+"\n");
                                br.close();
                                fr.close();
                                file.setReadOnly();
                            }
                        }
                        catch (IOException e1)
                        {
                            JOptionPane.showMessageDialog(panel1,"User not connected !");
                            e1.printStackTrace();
                            Thread.currentThread().stop();
                        }
                    }
                    if(fc!=null && fc.getSelectedFile()!=null)
                    {
                        progressbar pb=new progressbar("Sending...");
                        pb.start();
                        try
                        {
                            out.writeUTF("Attachment5psafv");
                            String[] arrOfStr=String.valueOf(fc.getSelectedFile()).split("/");
                            out.writeUTF(String.valueOf(arrOfStr[arrOfStr.length-1]));
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        FileInputStream fis=null;
                        BufferedInputStream bis=null;
                        OutputStream os=null;
                        try
                        {
                            File FILE_TO_SEND = fc.getSelectedFile();

                            btnMediaButton.setText("Attach");
                            taMsgSend.setText("");
                            taMsgSend.setEditable(true);

                            System.out.println(FILE_TO_SEND);
                            File myFile=new File(String.valueOf(FILE_TO_SEND));
                            byte[] mybytearray=new byte[(int) myFile.length()];
                            fis=new FileInputStream(myFile);
                            bis=new BufferedInputStream(fis);
                            System.out.println(myFile.length());
                            out.writeLong(myFile.length());
                            bis.read(mybytearray,0,mybytearray.length);
                            os=socket.getOutputStream();
                            System.out.println("Sending "+ FILE_TO_SEND+ "("+mybytearray.length+" bytes)");
                            os.write(mybytearray,0,mybytearray.length);
                            try
                            {
                                os.flush();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                            pb.setStop(false);
                            String filename=socket.getInetAddress().getHostName();
                            System.out.println("filename"+filename.replace('.','_'));
                            File file=new File("database/"+filename.replace(".","_")+".txt");
                            file.setWritable(true,false);
                            FileWriter fr=new FileWriter(file,true);
                            BufferedWriter br=new BufferedWriter(fr);
                            br.write("[You @ "+dtf.format(now)+"]"+msg+"\n");
                            br.close();
                            fr.close();
                            file.setReadOnly();

                            String fileName=fc.getSelectedFile().toString();
                            String extension = "";
                            int i = fileName.lastIndexOf('.');
                            if (i > 0) {
                                extension = fileName.substring(i+1);
                            }
                            System.out.println("extension: "+extension);
                            String text;
                            if(extension.equals("jpg") || extension.equals("png") || extension.equals("jpeg") || extension.equals("bmp") || extension.equals("gif")){
                                text = "<a href='file:///" + fc.getSelectedFile() + "'>" + "<img src='file:"+fc.getSelectedFile()+"' width=200 height=auto></img>" + "</a>";


                            }
                            else {
                                text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file:///" + fc.getSelectedFile() + "'>" +"   "+ fc.getSelectedFile() + "</a>";


                            }
                            try
                            {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                Element elem = doc.getElement("body");
                                String line = "<div class='div2'>"+text+"</div>";
                                System.out.println("line: "+line);
                                String htmlText = String.format("<p>%s</p>", line);
                                try {
                                    doc.insertBeforeEnd(elem, htmlText);
                                } catch (BadLocationException | IOException ex) {
                                    ex.printStackTrace();
                                }

                            }
                            catch (Exception e)
                            {

                            }

//                            float progress;
//                            progress=In.readFloat();
//                            while(progress<100)
//                                System.out.println("progress: "+progress);
                            System.out.println("Done");
//                            String newmsg = msg;
//                            newmsg=newmsg.trim();
//                            newmsg = "\n"+newmsg;
//                            try
//                            {
//                                doc.insertString(doc.getLength(), newmsg, right );
//                                doc.setParagraphAttributes(doc.getLength(), 1, right, false);
//                            }
//                            catch (Exception e)
//                            {
//
//                            }
//                            taHistory.setText(taHistory.getText()+"[You @ "+dtf.format(now)+"]: "+fc.getSelectedFile()+ "\n");
                        } catch (FileNotFoundException e) {
                            e.printStackTrace();
                        } catch (IOException e) {
                            e.printStackTrace();
                        } finally{
                            if(bis!=null) {
                                try{
                                    bis.close();
                                    fc=null;
                                } catch (IOException e) {
                                    e.printStackTrace();
                                }
                            }
                        }
                    }
                }
            });

            for( ActionListener al : btnMediaButton.getActionListeners() ) {
                btnMediaButton.removeActionListener( al );
            }

            btnMediaButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent actionEvent) {
                    if(fc==null)
                    {
                        fc = new JFileChooser();
                        fc.showOpenDialog(panel1);
                        System.out.println("FC "+fc.getSelectedFile());
                        btnMediaButton.setText("Cancel");
                        String fileName=fc.getSelectedFile().toString();
                        taMsgSend.setText(fileName);
                        taMsgSend.setEditable(false);


                    }
                    else
                    {
                        fc=null;
                        btnMediaButton.setText("Attach");
                        taMsgSend.setText("");
                        taMsgSend.setEditable(true);
                    }


                }
            });
            labelName.setText(socket.getInetAddress().getHostAddress());
        }
        catch(UnknownHostException u)
        {
            JOptionPane.showMessageDialog(panel1,"User Not Connected");
            System.out.println(u);
        }
        catch(IOException i)
        {
            System.out.println("error in block!");
            labelName.setText(address+" (offline)");
//            if(socket.isClosed())
//                JOptionPane.showMessageDialog(panel1,"User offline !");
//            String msssg=i.getMessage();
//            System.out.println(msssg);
//            System.out.println(i);
        }

        // close the connection
        //list click action
//        try
//        {
//            //input.close();
//            out.close();
//            socket.close();
//        }
//        catch(IOException i)
//        {
//            // System.out.println(i);
//        }
    }
}
