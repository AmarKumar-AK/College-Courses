package com.ipmessenger;

import javax.swing.*;
import javax.swing.text.*;
import javax.swing.text.html.HTMLDocument;
import java.awt.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class server extends Thread {
    static Vector<ClientHandler> ar = new Vector<>();
    private JEditorPane epHistory;
    static  int i=0;
    DefaultListModel<String> ips = new DefaultListModel<>();// counter for clients
    JList<String > listip;
    public DefaultListModel<String> getIps() {
        return ips;
    }

    // constructor with port
    public server(JEditorPane epHistory,DefaultListModel<String> ips,JList<String> listip)
    {
        this.epHistory=epHistory;
        this.ips = ips;
        this.listip = listip;
        listip.setModel(ips);
    }
    public void run()
    {
        // server is listening on port 5000

        try
        {
            ServerSocket ss = new ServerSocket(5000);

            Socket s;

            // running infinite loop for getting
            // client request
            while (true)
            {
                // Accept the incoming request
                System.out.println("server waiting! \n");
                s = ss.accept();

                int flag = 0;
                for (int i=0;i<ips.size();i++)
                {
                    String a= ips.get(i);
                    if(a.equals(s.getInetAddress().getHostAddress()))
                    {
                        //taHistory.append(ips.get(i));
                        flag=1;
                        break;
                    }
                }

                if(flag==0) {
                    ips.addElement(s.getInetAddress().getHostAddress());
                }
                int lastSelected = listip.getSelectedIndex();

                // ===========================
                // Writing ip's to file.
                // ===========================
                Set<String> hash_set = new HashSet<String>();
                System.out.println("Printing the  IP List");
                File file = new File("database/ip.txt");
                file.setWritable(true,false);
                FileWriter fr= new FileWriter(file, true);
                BufferedWriter br = new BufferedWriter(fr);

                for(int i=0;i<ips.size();i++)
                {
                    System.out.println(ips.get(i));
                    hash_set.add(ips.get(i));
                }
                Iterator<String> ip= hash_set.iterator();
                while(ip.hasNext()){
                    br.write(String.valueOf(ip.next()+"\n"));
                }
                br.close();
                fr.close();
                file.setReadOnly();

                System.out.println("New client request received : " + s);

                // obtain input and output streams
                DataInputStream dis = new DataInputStream(s.getInputStream());
                DataOutputStream dos = new DataOutputStream(s.getOutputStream());

                System.out.println("Creating a new handler for this client...");

                // Create a new handler object for handling this request.
                ClientHandler mtch = new ClientHandler(s,"client " + i, dis, dos,epHistory,ips,listip);


                // Create a new Thread with this object.
                Thread t = new Thread(mtch);

                System.out.println("Adding this client to active client list");

                // add this client to active clients list
                ar.add(mtch);

                // start the thread.
                t.start();

                // increment i for new client.
                // i is used for naming only, and can be replaced
                // by any naming scheme
                i++;

            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}

class ClientHandler implements Runnable
{
    Scanner scn = new Scanner(System.in);
    private String name;
    final DataInputStream dis;
    final DataOutputStream dos;
    private JEditorPane epHistory;
    Socket s;
    boolean isloggedin;
    boolean exit =false;
    DefaultListModel<String> ips = new DefaultListModel<>();
    JList<String>listip;
    public  static  String FILE_TO_RECEIVED=null;
    public final static int FILE_SIZE=1073741820;   //1GB
    // constructor
    public ClientHandler(Socket s, String name,
                         DataInputStream dis, DataOutputStream dos,JEditorPane epHistory,DefaultListModel<String>ips,JList<String> listip) {
        this.dis = dis;
        this.dos = dos;
        this.name = name;
        this.s = s;
        this.isloggedin=true;
        this.epHistory=epHistory;
        this.ips = ips;
        this.listip=listip;
    }

    @Override
    public void run() {

//        StyledDocument doc = taMsgRecv.getStyledDocument();
//
//        SimpleAttributeSet left = new SimpleAttributeSet();
//        StyleConstants.setBackground(left, Color.YELLOW);
//        StyleConstants.setForeground(left, Color.RED);
//        StyleConstants.setAlignment(left, StyleConstants.ALIGN_LEFT);
//        StyleConstants.setFontSize(left,24);
//        StyleConstants.setSpaceAbove(left,20);
//        SimpleAttributeSet right = new SimpleAttributeSet();
//        StyleConstants.setBackground(right, Color.GRAY);
//        StyleConstants.setForeground(right, Color.BLUE);
//        StyleConstants.setAlignment(right, StyleConstants.ALIGN_RIGHT);
//        StyleConstants.setFontSize(right,24);
//        StyleConstants.setSpaceAbove(right,20);

//        for(int i=0;i<ips.size();i++)
//        {
//
//        }

        String received;
        while (true)
        {
            try
            {
                // receive the string
                long recvfilesize=0;
                received = dis.readUTF();
                String ack = "ackOK";
                dos.writeUTF(ack);
                String filename=s.getInetAddress().getHostName();
                System.out.println("fn"+filename);

                if(received.equals("Attachment5psafv"))
                {
                    received=dis.readUTF();
                    received=received.replace(" ","_");
                    String path="media/";
                    FILE_TO_RECEIVED=path+received;
                    int bytesRead;
                    int current=0;
                    FileOutputStream fos=null;
                    BufferedOutputStream bos=null;
                    try
                    {
//                        progressBar pb = new progressBar();
//                        pb.start();
                        System.out.println("Connecting...........");
                        recvfilesize=dis.readLong();
                        System.out.println("recvFilesize: "+recvfilesize);

                        byte [] mybytearray=new byte[FILE_SIZE];
                        InputStream is=s.getInputStream();
                        fos=new FileOutputStream(FILE_TO_RECEIVED);
                        bos=new BufferedOutputStream(fos);
                        do {
                            bytesRead=is.read(mybytearray,current,(mybytearray.length-current));
                            System.out.println("bytesread : "+bytesRead);
                            System.out.println("current : "+current);
//                            pb.setPercent(current*100/((int)(recvfilesize)));
                            current+=bytesRead;
                        }while(current<recvfilesize);
//                        pb.setStop(false);
                        System.out.println(received);
                        if(!received.equals(""))
                        {
                            String msg =received;
                            msg = msg.trim();
                            msg = msg.replace(" ","_");
                            String fileName=System.getProperty("user.dir")+"/media/"+msg;
                            String extension = "";
                            int i = fileName.lastIndexOf('.');
                            if (i > 0) {
                                extension = fileName.substring(i+1);
                            }
                            System.out.println("extension: "+extension);
                            String text;
                            if(extension.equals("jpg") || extension.equals("png") || extension.equals("gif") || extension.equals("jpeg") || extension.equals("bmp")){
                                text = "<a href='file://" + fileName + "'>" + "<img src='file:"+fileName+"' width=200 height=auto></img>" + "</a>";


                            }
                            else {
                                text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file://" + fileName + "'>" +"   "+ msg + "</a>";


                            }
                            try
                            {
                                if(s.getInetAddress().getHostAddress().equals(listip.getSelectedValue()))
                                {
                                    System.out.println("firooooooooz\n");
//                                    doc.insertString(doc.getLength(), msg, left );
//                                    taMsgRecv.insertIcon(new ImageIcon("media/"+filename));
//                                    doc.setParagraphAttributes(doc.getLength(), 1, left, false);
                                    try
                                    {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                        HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                        Element elem = doc.getElement("body");
                                        String line = "<div class='div1'>"+text+"</div>";
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
                                }
                            }
                            catch (Exception e )
                            {

                            }
//                            taMsgRecv.setText(taMsgRecv.getText()+"["+s.getInetAddress().getHostAddress()+"] "+received+"\n");
                        }
                        bos.write(mybytearray,0,current);
                        bos.flush();

                        File file = new File("database/" + filename.replace(".", "_") + ".txt");
                        file.setWritable(true, false);
                        FileWriter fr = new FileWriter(file, true);
                        BufferedWriter br = new BufferedWriter(fr);
                        br.write("[" + s.getInetAddress().getHostAddress() + "]" + received + "\n");
                        br.close();
                        fr.close();
                        file.setReadOnly();





                        received=null;
                        System.out.println("file "+FILE_TO_RECEIVED+" downloaded ("+current+" bytes read)");
                    }
                    finally {
                        if(fos!=null)  fos.close();
                        if(bos!=null)  bos.close();
                    }

                }else {

                    if (received.equals("logout")) {
                        this.isloggedin = false;
                        this.s.close();
                        break;
                    }

                    System.out.println(received);
                    if (!received.equals("")) {
                        String msg =received;
                        msg = msg.trim();

                        if(s.getInetAddress().getHostAddress().equals(listip.getSelectedValue())) {
                            try {
                                //                                    doc.insertString(doc.getLength(), newmsg, right );
                                //                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                Element elem = doc.getElement("body");
                                String line = "<div class='div1'>" + msg + "</div>";
                                System.out.println("line: " + line);
                                String htmlText = String.format("<p>%s</p>", line);
                                try {
                                    doc.insertBeforeEnd(elem, htmlText);
                                } catch (BadLocationException | IOException ex) {
                                    ex.printStackTrace();
                                }

                            } catch (Exception e) {

                            }
                        }
//                        taMsgRecv.setText(taMsgRecv.getText() + "[" + s.getInetAddress().getHostAddress() + "] " + received + "\n");
                    }

                    File file = new File("database/" + filename.replace(".", "_") + ".txt");
                    file.setWritable(true, false);
                    FileWriter fr = new FileWriter(file, true);
                    BufferedWriter br = new BufferedWriter(fr);
                    br.write("[" + s.getInetAddress().getHostAddress() + "]" + received + "\n");
                    br.close();
                    fr.close();
                    file.setReadOnly();
                }

            } catch (IOException e) {
                try
                {
                    // closing resources
                    this.dis.close();
                    this.dos.close();

                }catch(IOException e1){
                    //e1.printStackTrace();
                }
                //e.printStackTrace();
            }

        }

    }
}
