screenWidth, screenHeight = 1920, 1080
companyButtonWidth, companyButtonHeight = int(screenWidth/5), int(screenHeight/20)
companyButtonXAxis, companyButtonYAxis = int(screenWidth/34),  int(screenHeight/9)
companyButtonSeparator, companyButtonFontSize = int(screenHeight/13.5), 17
edsWidth, edsHeight = int(screenWidth/2), int(screenHeight/21)

# def InitUI(self):

    #     menubar = wx.MenuBar()
    #     fileMenu = wx.Menu()
    #     fileItem = fileMenu.Append(wx.ID_EXIT, 'Quit', 'Quit application')
    #     menubar.Append(fileMenu, '&File')
    #     self.SetMenuBar(menubar)

    #     self.Bind(wx.EVT_MENU, self.OnClose, fileItem)

    #     self.headpnl=HeadNewPanel(self)
    #     imr = 'logor1.png'
    #     bmp1 = wx.Image(imr, wx.BITMAP_TYPE_ANY).ConvertToBitmap()
    #     self.bitmap1 = wx.StaticBitmap(self.headpnl, -1, bmp1, (int(w/34),15))
    #     self.headpnl.SetBackgroundColour("grey16")

    #     self.homepnl = NewPanel(self)
    #     imr = 'background.png'
    #     bmp1 = wx.Image(imr, wx.BITMAP_TYPE_ANY).ConvertToBitmap()
    #     self.bitmap1 = wx.StaticBitmap(self.homepnl, -1, bmp1, (0,0))

    #     pcButton = wx.Button(self.homepnl, label='Power Company', pos=(c.companyButtonXAxis, c.companyButtonYAxis),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     pcButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))

    #     dcButton = wx.Button(self.homepnl, label='Distribution Company', pos=(c.companyButtonXAxis, c.companyButtonYAxis + c.companyButtonSeparator),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     dcButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))

    #     tcButton = wx.Button(self.homepnl, label='Transmission Company', pos=(c.companyButtonXAxis, c.companyButtonYAxis + 2*c.companyButtonSeparator),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     tcButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))

    #     ebButton = wx.Button(self.homepnl, label='Electricity Board', pos=(c.companyButtonXAxis, c.companyButtonYAxis + 3*c.companyButtonSeparator),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     ebButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))



    #     pcButton.Bind(wx.EVT_BUTTON, self.pc)
    #     dcButton.Bind(wx.EVT_BUTTON, self.dc)
    #     tcButton.Bind(wx.EVT_BUTTON, self.tc)
    #     ebButton.Bind(wx.EVT_BUTTON, self.eb)

    #     l0 = wx.StaticText(self.homepnl, -1, "Customer Login ",pos=(750,170),size=(1000,1000))
    #     l0.SetFont(wx.Font(25,wx.FONTFAMILY_DEFAULT, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
    #     #l0.SetForegroundColour("white")
    #     errormsg = wx.StaticText(self.homepnl, -1, " ",pos=(750,400), size=(400, 30))
    #     l1 = wx.StaticText(self.homepnl, -1, "Customer ID : ",pos=(620,260), size=(200,100))
    #     l1.SetForegroundColour("white")
    #     l1.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))
    #     t1 = wx.TextCtrl(self.homepnl,style= wx.TE_PROCESS_ENTER,pos=(810,260),size=(400,40))


    #     l2 = wx.StaticText(self.homepnl, -1, "Password    : ",pos=(620,330), size=(200,100))
    #     l2.SetForegroundColour("white")
    #     l2.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))
    #     t2 = wx.TextCtrl(self.homepnl,style = wx.TE_PASSWORD|wx.TE_PROCESS_ENTER,pos=(810,330),size=(400,40))

    #     t1.Bind(wx.EVT_TEXT_ENTER,partial(self.Login,t1=t1,t2=t2,errormsg=errormsg))
    #     t2.Bind(wx.EVT_TEXT_ENTER,partial(self.Login,t1=t1,t2=t2,errormsg=errormsg))

    #     loginButton = wx.Button(self.homepnl, label='Log In', pos=(980, 450), size=(int(c.companyButtonWidth/2), c.companyButtonHeight))
    #     loginButton.Bind(wx.EVT_BUTTON, partial(self.Login,t1=t1,t2=t2,errormsg=errormsg))
    #     loginButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))


    #     NacButton = wx.Button(self.homepnl, label='Not a Consumer', pos=(700, 450), size=(int(c.companyButtonWidth/1.8), c.companyButtonHeight))
    #     NacButton.Bind(wx.EVT_BUTTON, partial(self.EmpLoginForm,pt1=t1,pt2=t2,perrormsg=errormsg))
    #     NacButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))


    #     newConButton = wx.Button(self.homepnl, label='Apply New Connection', pos=(1400,100),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     newConButton.Bind(wx.EVT_BUTTON,self.newConnection)
    #     newConButton.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))


    #     statBtn = wx.Button(self.homepnl, label='Know Your Conn. status', pos=(1400,200),size=(c.companyButtonWidth, c.companyButtonHeight))
    #     statBtn.Bind(wx.EVT_BUTTON,self.ncStat)
    #     statBtn.SetFont(wx.Font(c.companyButtonFontSize, wx.FONTFAMILY_DEFAULT, 0, 90, underline = False,faceName =""))


    #     #w,h=wx.GetDisplaySize()
    #     self.SetSize((w,h))
    #     self.SetMaxSize((w,h))
    #     self.SetMinSize((w,h))
    #     self.SetTitle('Power Distribution System')
    #     self.Centre()
    #     self.homepnl.Bind(wx.EVT_PAINT, partial(self.OnPaint,op=self.homepnl))
    #     #self.Centre()
    #     #self.Show(True)
