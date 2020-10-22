package com.ipmessenger;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.event.AncestorListener;
import javax.swing.event.HyperlinkEvent;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.text.*;
import javax.swing.text.html.HTMLDocument;
import javax.swing.text.html.HTMLEditorKit;
import java.awt.*;
import java.awt.desktop.SystemEventListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.net.*;
import java.util.*;

import static java.lang.Thread.sleep;

public class mainFrame {
    private JPanel panel1;      //area where we get message
    private JButton btnSend;    //area where we type ip to search
    private JTextField tfNewIp;    //button for searching ip
    private JButton btnSearchIp;    //area where list of ip is shown
    private  JButton refresh;
    private JList<String> listIp;
    private JSplitPane sp;
    private JPanel rpanel;
    private JPanel lpanel;    //name of person with whom you are chatting
    private JLabel labelName;    //area where we type message
    private JTextArea taSendMsg;
    private JButton btnMediaButton;
    private JButton moreButton;
    private JPanel userpnl;
    private JLabel labelicon;
    private JButton savedMediaButton;
    private JEditorPane epHistory;
    Socket lastClient=null;
    DataOutputStream lastOut=null;
    int lc =1;
    int bc=1;
    int selected;
    private Socket currentClient = null;
    private clientConnect currClient ;

    DefaultListModel<String> ips = new DefaultListModel<>();


    public mainFrame() throws IOException {

        File backgroundd = new File("./msgbackground.jpg");
        URL urll = backgroundd.toURI().toURL();
//
//        epHistory.setContentType("text/html");
//        epHistory.setText("<html><body style='color: #ffffff; background-image: url(" + urll.toString() + ");'>Boo</body></html>");

        // getting own system ips
        compairingOwnIp compairingOwnIp = new compairingOwnIp();
        ArrayList<String> myips = compairingOwnIp.getMyips();
        for(int i=0;i<myips.size();i++)
        {
            if(myips.get(i).equals("127.0.0.1") || myips.get(i).equals("0.0.0.0"))
            {
                myips.remove(i);
            }
        }

        //user png
        BufferedImage image = ImageIO.read(new File("mainuser1.png"));
//        Graphics2D g = (Graphics2D) image.getGraphics();
//        g.setStroke(new BasicStroke(3));
//        g.setColor(Color.BLUE);
//        g.drawRect(0, 0, image.getWidth() - 10, image.getHeight() - 10);
        labelicon.setLocation(0,10);
        labelicon.setIcon(new ImageIcon(image));
        compairingOwnIp c = new compairingOwnIp();
        ArrayList<String> mylist = c.getMyips();
        labelicon.setText(mylist.get(0));
        //

        HTMLEditorKit htmlEditorKit = new HTMLEditorKit();
        epHistory.setEditorKit(htmlEditorKit);

        Document doc = htmlEditorKit.createDefaultDocument();
        epHistory.setDocument(doc);
        File background = new File("icon_2.png");
        URL url = background.getCanonicalFile().toURI().toURL();
        epHistory.setText("<html><head><style type='text/css'>" +//"body{background-image: url('"+urll.toString()+ "' );background-repeat: 'none';}"+
                ".div1{width: 5px; max-width: 5px; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative;margin-left:0; margin-right:500;}" +
                ".div2{width: 40; max-width: 40; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative; margin-left:500; margin-right:0;}" +
                "</style></head> <body id='body' > </body></html>");

        epHistory.setEditable(false);
        epHistory.addHyperlinkListener(e -> {
            if (HyperlinkEvent.EventType.ACTIVATED.equals(e.getEventType())) {
                System.out.println(e.getURL());
                Desktop desktop = Desktop.getDesktop();
                try {
                    desktop.browse(e.getURL().toURI());
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });












        //Reading iplist from file ip.txt
        Set<String> hash_set = new HashSet<String>();
        File ipsfile = new File("database/ip.txt");
        if(ipsfile.exists())
        {
            BufferedReader wbr = new BufferedReader(new FileReader(ipsfile));
            String st;
            while((st = wbr.readLine())!=null){
                hash_set.add(st);
            }
        }

        Iterator<String> j = hash_set.iterator();

        for(int i=0;i<myips.size();i++)
            System.out.println(myips.get(i));
        while(j.hasNext()){
            String ip =j.next();
            int flag =1;
            for(int i=0;i<myips.size();i++)
            {
                if(ip.equals(myips.get(i)))
                {
                    flag =0;
                    break;
                }
            }
            if(flag==1)
            {
                ips.addElement(ip);
            }
        }

        // fetching online users
        refresh.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                listIp.setEnabled(false);
                String myip = myips.get(myips.size()-1);
                String subnet="";
                int dotcount=0;
                for(int i=0;i<myip.length();i++)
                {
                    if(myip.charAt(i)=='.' )
                    {
                        dotcount++;
                        if(dotcount==2)
                            break;
                        subnet+=myip.charAt(i);
                    }
                    else
                        subnet+=myip.charAt(i);
                }
                checkingAvailIps checkingAvailIps = new checkingAvailIps(listIp,ips,subnet,myips);
                checkingAvailIps.start();
                progressbar pb=new progressbar("Searching online users...");
                pb.start();
                while (checkingAvailIps.getStatus()!=0)
                {
                    System.out.println("status = "+checkingAvailIps.getStatus());
                    //System.out.println("");
                }
                pb.setStop(false);
//
//                for(int i=0; i<ips.size(); i++){
//                    System.out.println("Ip from ips: "+ips.get(i));
//                }
//                Iterator<String> k = hash_set.iterator();
//                ips.clear();
//                while(k.hasNext()){
//                    String s = k.next();
//                    ips.addElement(s);
//                    System.out.println("IP: "+s);
//                }
                listIp.setEnabled(true);
                for( AncestorListener al : refresh.getAncestorListeners() ) {
                    refresh.removeActionListener((ActionListener) al);
                }

            }
        });
        //

        listIp.setModel(ips);
        try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName()); }
        catch (UnsupportedLookAndFeelException e) {}
        catch (ClassNotFoundException e) {}
        catch (InstantiationException e) {}
        catch (IllegalAccessException e) {}

//        taHistory.setAutoscrolls(true);
//        StyledDocument doc = taHistory.getStyledDocument();
//
//        SimpleAttributeSet left = new SimpleAttributeSet();
//        StyleConstants.setBackground(left, Color.YELLOW);
//        StyleConstants.setForeground(left, Color.RED);
//        StyleConstants.setAlignment(left, StyleConstants.ALIGN_LEFT);
//        StyleConstants.setFontSize(left,24);
//        StyleConstants.setSpaceAbove(left,20);
//
//        SimpleAttributeSet right = new SimpleAttributeSet();
//        StyleConstants.setBackground(right, Color.black);
//        StyleConstants.setForeground(right, Color.white);
//        StyleConstants.setAlignment(right, StyleConstants.ALIGN_RIGHT);
//        StyleConstants.setFontSize(right,24);
//        StyleConstants.setSpaceAbove(right,20);



//        taHistory.setMargin(new Insets(10,10,10,10));

        server server = new server(epHistory,ips,listIp);
        server.start();

//        taHistory.setAutoscrolls(true);
        listIp.setFixedCellHeight(40);
        listIp.setFixedCellWidth(10);
        listIp.setBorder(BorderFactory.createRaisedBevelBorder());
        listIp.setCellRenderer(getRenderer());
//        listIp.setForeground(Color.blue);
        ImageIcon icon = new ImageIcon("icon_2.png");



        tfNewIp.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode()==KeyEvent.VK_ENTER){
                    btnSearchIp.doClick();
                }
            }
        });

        btnSearchIp.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String temp = tfNewIp.getText();
                int flag_ownip =1;
                for(int i=0;i<myips.size();i++)
                {
                    System.out.println("myip"+myips.get(i));
                    if(temp.equals(myips.get(i)))
                    {
                        flag_ownip =0;
                        break;
                    }

                }
                System.out.println("fo"+flag_ownip);
                if(!tfNewIp.getText().equals("") && flag_ownip==1)
                {
                    epHistory.setText("<html><head><style type='text/css'>" +
                            ".div1{width: 5px; max-width: 5px; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative;margin-left:0; margin-right:500;}" +
                            ".div2{width: 40; max-width: 40; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative; margin-left:500; margin-right:0;}" +
                            "</style></head> <body id='body' > </body></html>");
                    String chat="";
                    char[] ch={0};
                    if(lc==0)
                    {
                        try{
                            System.out.println("lastsocket = "+lastClient);
                            if(lastOut!=null)
                                lastClient.close();
                        }
                        catch (IOException i){
                            System.out.println(i);
                        };
                        try{
                            if(lastOut!=null)
                                lastOut.close();
                        }
                        catch (IOException i){

                        };

                        for( ActionListener al : btnSend.getActionListeners() ) {
                            btnSend.removeActionListener( al );
                        }

                    }


                    String filename=temp;
                   // taHistory.setText("");
                    try
                    {
                        File file=new File("database/"+filename.replace(".","_")+".txt");
                        Scanner sc=new Scanner(file);
                        sc.useDelimiter("\\Z");
                        chat = sc.next();
                        System.out.println(chat);
//                    Scanner scanner = new Scanner(chat);
                        ch = chat.toCharArray();

                        System.out.println(chat.length());


//                    taHistory.setText();
//                        String msgsave=sc.next()+"\n";
//                        taHistory.setText(msgsave);


//                    taHistory.setText();
//                    taHistory.setText(sc.next());
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    }
                    int flag = 0;
                    for (int i=0;i<ips.size();i++)
                    {
                        String a= ips.get(i);
                        if(a.equals(temp))
                        {
                            //taHistory.append(ips.get(i));
                            flag=1;
//                            System.out.println("firoz................");
//                        listIp.setSelectedIndex(1);
                            listIp.setSelectedIndex(i);
                            break;
                        }
                    }

                    tfNewIp.setText("");
                    System.out.println(temp);

                    clientConnect client = new clientConnect(temp,5000,taSendMsg,epHistory,btnSend,btnMediaButton,panel1,labelName);
                    try {
                        currentClient = client.getSocket();
                        currClient = client;
                        client.start();
                        System.out.println("client = "+currentClient);
                        if(lastClient!=null)
                            labelName.setText(temp);
                    } catch (UnknownError eee) {
                        eee.printStackTrace();
                    }
                    try {
                        client.join();
                    } catch (InterruptedException ee) {
                        ee.printStackTrace();
                    }
                    lastClient=client.getSocket();
                    System.out.println("socket = "+lastClient);
                    lastOut=client.getOut();
                    System.out.println("out = "+lastOut);
                    if(lastOut!=null && flag!=1)
                    {
                        ips.addElement(temp);
                    }
                    //listIp.setSelectedIndex(ips.size()-1);
                    lc=0;

                    String msg = "";
                    for(int i=0;i<ch.length-1;i++)
                    {
//                        System.out.println("i");
                        char a=ch[i],b=ch[i+1];
                        if(a=='[' && b=='Y')
                        {
                            while(ch[i]!=']')
                            {
//                                System.out.println("j"+i);
                                i++;
                            }
                            i++;
                            msg = "";
                            while(ch[i]!='[')
                            {
//                                System.out.println("k"+i);
                                msg+=ch[i];
                                i++;
                                if(i==chat.length()){
                                    break;
                                }
                            }

                            i--;
                            ////////////right
                            msg =msg.trim();

//                                System.out.println("::::r"+msg);
//                                doc.insertString(doc.getLength(), msg, right );
//                                doc.setParagraphAttributes(doc.getLength(), 1, right, false);

                            File tempFile = new File(msg);
                            boolean exists = tempFile.exists();
                            if(!exists) {
                                try {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                    HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                    Element elem = doc.getElement("body");
                                    String line = "<div class='div2'>" + msg + "</div>";
                                    System.out.println("line: " + line);
                                    String htmlText = String.format("<p>%s</p>", line);
                                    try {
                                        doc.insertBeforeEnd(elem, htmlText);
                                    } catch (BadLocationException | IOException ex) {
                                        ex.printStackTrace();
                                    }

                                } catch (Exception e1) {

                                }
                            }
                            else
                            {
                                //formatted output
                                String fileName=msg;
                                String extension = "";
                                int j = fileName.lastIndexOf('.');
                                if (j > 0) {
                                    extension = fileName.substring(j+1);
                                }
                                System.out.println("extension: "+extension);
                                String text;
                                if(extension.equals("jpg") || extension.equals("png") || extension.equals("jpeg") || extension.equals("bmp") || extension.equals("gif")){
                                    text = "<a href='file:///" + msg + "'>" + "<img src='file:"+msg+"' width=200 height=auto></img>" + "</a>";


                                }
                                else {
                                    text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file:///" + msg + "'>" +"   "+ msg + "</a>";


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
                                catch (Exception e5)
                                {

                                }
                            }

                        }
                        else if(a=='[' && b!='Y')
                        {
                            while(ch[i]!=']')
                            {
//                                System.out.println("l"+i);
                                i++;
                            }
                            i++;
                            msg = "";
                            while(ch[i]!='[')
                            {
//                                System.out.println("m"+i);
                                msg+=ch[i];
//                                System.out.println(msg);
                                i++;
                                if(i==chat.length()){
                                    break;
                                }
                            }

                            i--;
//                            System.out.println("amar"+i);
                            //////////////left
                            msg =msg.trim();

                            //System.out.println("::::l"+msg);
//                                doc.insertString(doc.getLength(), msg, left );
//                                doc.setParagraphAttributes(doc.getLength(), 1, left, false);
                            File tempFile = new File(System.getProperty("user.dir")+"/media/"+msg);
                            boolean exists = tempFile.exists();
                            if(!exists) {
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

                                } catch (Exception e2) {

                                }
                            }
                            else
                            {
                                //formatted output
                                String fileName=System.getProperty("user.dir")+"/media/"+msg;
                                String extension = "";
                                int j = fileName.lastIndexOf('.');
                                if (j > 0) {
                                    extension = fileName.substring(j+1);
                                }
                                System.out.println("extension: "+extension);
                                String text;
                                if(extension.equals("jpg") || extension.equals("png") || extension.equals("jpeg") || extension.equals("bmp") || extension.equals("gif")){
                                    text = "<a href='file://" + fileName + "'>" + "<img src='file:"+fileName+"' width=200 height=auto></img>" + "</a>";


                                }
                                else {
                                    text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file://" + fileName + "'>" +"   "+ msg + "</a>";


                                }
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
                                catch (Exception e5)
                                {

                                }
                            }

                        }
                    }
                }
                else
                {
                    JOptionPane.showMessageDialog(panel1,"Please enter valid Ip !");
                }


            }
        });


        listIp.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                listIp.setCellRenderer(getRenderer());
                String chat ="";
                char[] ch;
                if(!e.getValueIsAdjusting())
                {
                    if(bc==0)
                    {
                        try{
                            System.out.println("lastsocket = "+lastClient);
                            if(lastOut!=null)
                                lastClient.close();
                        }
                        catch (IOException i){
                            System.out.println(i);
                        };
                        try{
                            if(lastOut!=null)
                                lastOut.close();
                        }
                        catch (IOException i){

                        };
                    }
                    String temp1=listIp.getSelectedValue();
                    selected=listIp.getSelectedIndex();
//                    listIp.setSelectionBackground(Color.green);
                    String filename=temp1;
//                    taHistory.setText("");
                    epHistory.setText("<html><head><style type='text/css'>" +
                            ".div1{width: 5px; max-width: 5px; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative;margin-left:0; margin-right:500;}" +
                            ".div2{width: 40; max-width: 40; margin: 5px auto; background: #C4D6D6; color: #fff; padding: 10px; text-align: center; font-weight: 900; font-family: arial; position: relative; margin-left:500; margin-right:0;}" +
                            "</style></head> <body id='body' > </body></html>");
                    try
                    {
                        File file=new File("database/"+filename.replace(".","_")+".txt");
                        Scanner sc=new Scanner(file);
                        sc.useDelimiter("\\Z");
                        chat = sc.next();
                        System.out.println(chat);
//                    Scanner scanner = new Scanner(chat);
                        ch = chat.toCharArray();
                        String msg = "";
                        System.out.println(chat.length());
                        for(int i=0;i<ch.length-1;i++)
                        {
//                        System.out.println("i");
                            char a=ch[i],b=ch[i+1];
                            if(a=='[' && b=='Y')
                            {
                                while(ch[i]!=']')
                                {
//                                System.out.println("j"+i);
                                    i++;
                                }
                                i++;
                                msg = "";
                                while(ch[i]!='[')
                                {
//                                System.out.println("k"+i);
                                    msg+=ch[i];
                                    i++;
                                    if(i==chat.length()){
                                        break;
                                    }
                                }

                                i--;
                                ////////////right
                                msg =msg.trim();

//                                    System.out.println("::::r"+msg);
//                                    doc.insertString(doc.getLength(), msg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                File tempFile = new File(msg);
                                boolean exists = tempFile.exists();
                                if(!exists) {
                                    try {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                        HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                        Element elem = doc.getElement("body");
                                        String line = "<div class='div2'>" + msg + "</div>";
                                        System.out.println("line: " + line);
                                        String htmlText = String.format("<p>%s</p>", line);
                                        try {
                                            doc.insertBeforeEnd(elem, htmlText);
                                        } catch (BadLocationException | IOException ex) {
                                            ex.printStackTrace();
                                        }

                                    } catch (Exception e3) {
                                    }
                                }
                                else
                                {
                                    //formatted output
                                    String fileName=msg;
                                    String extension = "";
                                    int j = fileName.lastIndexOf('.');
                                    if (j > 0) {
                                        extension = fileName.substring(j+1);
                                    }
                                    System.out.println("extension: "+extension);
                                    String text;
                                    if(extension.equals("jpg") || extension.equals("png") || extension.equals("jpeg") || extension.equals("bmp") || extension.equals("gif")){
                                        text = "<a href='file:///" + msg + "'>" + "<img src='file:"+msg+"' width=200 height=auto></img>" + "</a>";


                                    }
                                    else {
                                        text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file:///" + msg + "'>" +"   "+ msg + "</a>";


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
                                    catch (Exception e5)
                                    {

                                    }
                                }

                            }
                            else if(a=='[' && b!='Y')
                            {
                                while(ch[i]!=']')
                                {
//                                System.out.println("l"+i);
                                    i++;
                                }
                                i++;
                                msg = "";
                                while(ch[i]!='[')
                                {
//                                System.out.println("m"+i);
                                    msg+=ch[i];
//                                    System.out.println(msg);
                                    i++;
                                    if(i==chat.length()){
                                        break;
                                    }
                                }

                                i--;
//                                System.out.println("amar"+i);
                                //////////////left
                                msg =msg.trim();

//                                    System.out.println("::::l"+msg);
//                                    doc.insertString(doc.getLength(), msg, left );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, left, false);
                                File tempFile = new File(System.getProperty("user.dir")+"/media/"+msg);
                                boolean exists = tempFile.exists();
                                if(!exists){
                                try
                                {
//                                    doc.insertString(doc.getLength(), newmsg, right );
//                                    doc.setParagraphAttributes(doc.getLength(), 1, right, false);
                                    HTMLDocument doc = (HTMLDocument) epHistory.getDocument();
                                    Element elem = doc.getElement("body");
                                    String line = "<div class='div1'>"+msg+"</div>";
                                    System.out.println("line: "+line);
                                    String htmlText = String.format("<p>%s</p>", line);
                                    try {
                                        doc.insertBeforeEnd(elem, htmlText);
                                    } catch (BadLocationException | IOException ex) {
                                        ex.printStackTrace();
                                    }

                                }
                                catch (Exception e4)
                                {

                                }}
                                else
                                {
                                    //formatted output
                                    String fileName=System.getProperty("user.dir")+"/media/"+msg;
                                    String extension = "";
                                    int j = fileName.lastIndexOf('.');
                                    if (j > 0) {
                                        extension = fileName.substring(j+1);
                                    }
                                    System.out.println("extension: "+extension);
                                    String text;
                                    if(extension.equals("jpg") || extension.equals("png") || extension.equals("jpeg") || extension.equals("bmp") || extension.equals("gif")){
                                        text = "<a href='file://" + fileName + "'>" + "<img src='file:"+fileName+"' width=200 height=auto></img>" + "</a>";


                                    }
                                    else {
                                        text = "<img src='file:./file.png' width=50 height=auto></img>" +"<a href='file://" + fileName + "'>" +"   "+ msg + "</a>";


                                    }
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
                                    catch (Exception e5)
                                    {

                                    }
                                }

                            }
                        }
//                        String msgsave=sc.next()+"\n";
//                        taHistory.setText(msgsave);
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    }
                    System.out.println("selected ip = "+temp1);
                    System.out.println(temp1);
                    //listIp.setModel(ips);

                    clientConnect client = new clientConnect(temp1,5000,taSendMsg,epHistory,btnSend,btnMediaButton,panel1,labelName);
                    try {
                        currentClient = client.getSocket();
                        client.start();
                        currClient = client;

                        System.out.println("client = "+currentClient);
//                        if(lastClient!=null)
//                        {
//                            labelName.setText(temp1);
//                        }
//                        else{
//                            JOptionPane.showMessageDialog(panel1,"User is offline !");
//                        }
                    } catch (UnknownError eee) {
                        eee.printStackTrace();
                    }
                    try {
                        client.join();
                    } catch (InterruptedException ee) {
                        ee.printStackTrace();
                    }

                    lastClient=client.getSocket();
                    System.out.println("socket = "+lastClient);
                    bc=0;
                }
            }
        });
        moreButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                Socket socket = currClient.getSocket();
                if(socket!=null)
                {
                    try{
//                        System.out.println("Last Client: "+lastClient);
//                        System.out.println("Current Client : " + currentClient);
                        JOptionPane.showMessageDialog(panel1, "IP: " + socket.getInetAddress().getHostAddress() + "\nPort: " + socket.getPort() + "\nLocal Port: " + socket.getLocalPort());
                    } catch(NullPointerException e) {
                    JOptionPane.showMessageDialog(panel1, "User is offline !");
                        System.out.println(e);
                    }
                }
                else
                {
                    JOptionPane.showMessageDialog(panel1,"User is offline !");
                }


            }
        });
        savedMediaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                try {
                    System.out.println("Saved media button clicked!");
                    Desktop.getDesktop().open(new File("media"));
                } catch(IOException e){
                    System.out.println(e);
                }
            }
        });
    }

    private ListCellRenderer<? super String> getRenderer() {
        return new DefaultListCellRenderer(){
            @Override
            public Component getListCellRendererComponent(JList<?> list,
                                                          Object value, int index, boolean isSelected,
                                                          boolean cellHasFocus) {
                JLabel listCellRendererComponent = (JLabel) super.getListCellRendererComponent(list, value, index, isSelected,cellHasFocus);
                System.out.println("sssss = "+index);
                listCellRendererComponent.setBorder(BorderFactory.createRaisedSoftBevelBorder());
                Color ipscolor = new Color(255, 255, 255);
                listCellRendererComponent.setBackground(ipscolor);
                if(index==selected)
                {
                    Color sele = new Color(172, 190, 200);
                    listCellRendererComponent.setBackground(sele);
                }
                ImageIcon icon = new ImageIcon("c1.png");
                listCellRendererComponent.setIcon(icon);
                //getListCellRendererComponent.
                return listCellRendererComponent;
            }
        };
    }

    public static void main(String[] args) throws IOException {
        JFrame frame = new JFrame("Ip Messenger");
        frame.setSize(1080,720);
        Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
        frame.setLocation(dim.width/2-frame.getSize().width/2,dim.height/2-frame.getSize().height/2);
        frame.setContentPane(new mainFrame().panel1);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        splashScreen spp = new splashScreen();
        while (spp.getStatus()!=0)
        {
            System.out.println("waiting");
        }
        frame.setVisible(true);
    }
}
