import sys
import math; #For pow and sqrt
import sys;
import time
# import matplotlib.pyplot as a
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg,NavigationToolbar2Tk
from matplotlib.figure import Figure
from random import shuffle, uniform;
import threading as th
from functools import partial
try:
    import Tkinter as tk
except ImportError:
    import tkinter as tk

try:
    import ttk
    py3 = False
except ImportError:
    import tkinter.ttk as ttk
    py3 = True


fig = Figure(figsize=(5,5), dpi=100)
a = fig.add_subplot(111)
ret=[[0]*2]*3
color=["red","blue","green"]
lines=[]
centroid=[]
datapoints=[]


#import firoz_support

def vp_start_gui():
    '''Starting point when module is the main routine.'''
    global val, w, root
    root = tk.Tk()
    top = Toplevel1 (root)
    #firoz_support.init(root, top)
    root.mainloop()

w = None
def create_Toplevel1(root, *args, **kwargs):
    '''Starting point when module is imported by another program.'''
    global w, w_win, rt
    rt = root
    w = tk.Toplevel (root)
    top = Toplevel1 (w)
    #firoz_support.init(w, top, *args, **kwargs)
    return (w, top)

def destroy_Toplevel1():
    global w
    w.destroy()
    w = None

def ReadData(fileName):
    #Read the file, splitting by lines
    f = open(fileName,'r');
    liness = f.read().splitlines();
    f.close();

    items = [];

    for i in range(1,len(liness)):
        line = liness[i].split(',');
        itemFeatures = [];

        for j in range(len(line)-1):
            v = float(line[j]); #Convert feature value to float
            itemFeatures.append(v); #Add feature value to dict

        items.append(itemFeatures);

    shuffle(items);

    return items;


###_Auxiliary Function_###
def FindColMinMax(items):
    n = len(items[0]);
    minima = [sys.maxsize for i in range(n)];
    maxima = [-sys.maxsize -1 for i in range(n)];

    for item in items:
        for f in range(len(item)):
            if(item[f] < minima[f]):
                minima[f] = item[f];

            if(item[f] > maxima[f]):
                maxima[f] = item[f];

    return minima,maxima;

def EuclideanDistance(x,y):
    S = 0; #The sum of the squared differences of the elements
    for i in range(len(x)):
        S += math.pow(x[i]-y[i],2);
    ret=math.sqrt(S)
    #print("euuci"+str(ret))

    return ret; #The square root of the sum

def InitializeMeans(items,k,cMin,cMax,Canvas12):
    #Initialize means to random numbers between
    #the min and max of each column/feature

    f = len(items[0]); #number of features
    means = [[0 for i in range(f)] for j in range(k)];

    j=0;
    for mean in means:
        for i in range(len(mean)):
            #Set value to a random float
            #(adding +-1 to avoid a wide placement of a mean)
            mean[i] = uniform(cMin[i]+1,cMax[i]-1);
        #a.clear()
        centroid.append(a.scatter(mean[0],mean[1],c=color[j],alpha=0.5,s=50,marker="D"))
        Canvas12.draw()
        #a.pause(0.1)
        j=j+1
    #a.show();
    return means;

def UpdateMean(n,mean,item):
    for i in range(len(mean)):
        m = mean[i];
        m = (m*(n-1)+item[i])/float(n);
        mean[i] = round(m,3);

    return mean;

def FindClusters(means,items,Canvas12):
    clusters = [[] for i in range(len(means))]; #Init clusters

    for item in items:
        #Classify item into a cluster
        index = Classify(means,item);
        print("means "+str(means[index]))
        print("item "+str(item))
        x=[means[index][0],item[0]]
        y=[means[index][1],item[1]]
        #a.clear()
        a.scatter(item[0],item[1],c=color[index],alpha=0.5,s=10);
        Canvas12.draw()
        #a.pause(0.1)
        #a.clear()
        lines.append(a.plot(x, y, linewidth=0.5,c=color[index],gid=1)[0])
        Canvas12.draw()
        #a.pause(0.1)
        #print("firoz")
        #Add item to cluster
        clusters[index].append(item);

    return clusters;


###_Core Functions_###
def Classify(means,item):
    #Classify item to the mean with minimum distance

    minimum = sys.maxsize;
    index = -1;

    for i in range(len(means)):
        #Find distance from item to mean
        dis = EuclideanDistance(item,means[i]);
        if(dis < minimum):
            minimum = dis;
            index = i;

    return index;

def RecomputeCC(cluster,mean,i):
    mean_c=[0]*2
    for item in cluster:
        mean_c[0]=mean_c[0]+item[0]
        mean_c[1]=mean_c[1]+item[1]
    if(len(cluster)!=0):
        mean_c[0]=mean_c[0]/len(cluster)
        mean_c[1]=mean_c[1]/len(cluster)
    #return mean_c
    ret[i]=mean_c


def CalculateMeans(k,items,Canvas12,maxIterations=10):
    #Find the minima and maxima for columns
    cMin, cMax = FindColMinMax(items);
    #Initialize means at random points
    means = InitializeMeans(items,k,cMin,cMax,Canvas12);
    #print(means)
    #Calculate means
    for e in range(maxIterations):
        #If no change of cluster occurs, halt
        noChange = True;
        clusters = FindClusters(means,items,Canvas12);
        #print(clusters)
        t=[0]*k
        print(lines)
        for line in lines:
            #print(line)
            line.remove()
            #a.pause(0.1)
        lines.clear()
        for c in centroid:
            c.remove()
            #a.pause(0.1)
        centroid.clear()
        for i in range(len(means)):
            t[i]=th.Thread(target=RecomputeCC , args=(clusters[i],means[i],i,))
            #print("tid = "+str(t[i]))
            t[i].start()
        means_cth=[0]*k
        for i in range(len(means)):
            t[i].join()
            #a.clear()
            centroid.append(a.scatter(ret[i][0],ret[i][1],c=color[i],alpha=0.5,s=50,marker="D"))
            Canvas12.draw()
            #print(centroid)
            #a.pause(0.1)
            #print("means + "+str(ret[i]))
            if(means[i] != ret[i]):
                noChange = False


        #Nothing changed, return
        if(noChange):
            print("completedddddddddddddddddddddddddddd")
            break;
        for i in range(len(means)):
            means[i] = ret[i]
    FindClusters(means,items,Canvas12)
    return means;

def CutToTwoFeatures(items,indexA,indexB):
    n = len(items);
    X = [];
    for i in range(n):
        item = items[i];
        newItem = [item[indexA],item[indexB]];
        X.append(newItem);

    return X;

class Toplevel1:
    def __init__(self, top=None):
        '''This class configures and populates the toplevel window.
           top is the toplevel containing window.'''
        _bgcolor = '#d9d9d9'  # X11 color: 'gray85'
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#d9d9d9' # X11 color: 'gray85'
        _ana1color = '#d9d9d9' # X11 color: 'gray85'
        _ana2color = '#ececec' # Closest X11 color: 'gray92'
        font10 = "-family gothic -size 13 -weight normal -slant roman "  \
            "-underline 0 -overstrike 0"
        self.style = ttk.Style()
        if sys.platform == "win32":
            self.style.theme_use('winnative')
        self.style.configure('.',background=_bgcolor)
        self.style.configure('.',foreground=_fgcolor)
        self.style.configure('.',font="TkDefaultFont")
        self.style.map('.',background=
            [('selected', _compcolor), ('active',_ana2color)])

        top.geometry("600x450+466+135")
        top.minsize(1, 1)
        top.maxsize(1351, 738)
        top.resizable(1, 1)
        top.title("New Toplevel")

        self.Frame1 = tk.Frame(top)
        self.Frame1.place(relx=0.017, rely=0.022, relheight=0.967
                , relwidth=0.975)
        self.Frame1.configure(relief='ridge')
        self.Frame1.configure(borderwidth="2")
        self.Frame1.configure(relief="ridge")

        self.Label1 = tk.Label(self.Frame1)
        self.Label1.place(relx=0.188, rely=0.023, height=25, width=359)
        self.Label1.configure(font=font10)
        self.Label1.configure(text='''Clutering Package''')

        self.TSeparator1 = ttk.Separator(self.Frame1)
        self.TSeparator1.place(relx=0.328, rely=0.166, relheight=0.851)
        self.TSeparator1.configure(orient="vertical")

        self.TSeparator2 = ttk.Separator(self.Frame1)
        self.TSeparator2.place(relx=-0.014, rely=0.143, relwidth=1.009)

        self.Button_k = tk.Button(self.Frame1)
        self.Button_k.place(relx=0.017, rely=0.161, height=45, width=170)
        self.Button_k.configure(background="#4cd850")
        self.Button_k.configure(borderwidth="3")
        self.Button_k.configure(text='''K-Means''')



        self.Button2 = tk.Button(self.Frame1)
        self.Button2.place(relx=0.017, rely=0.299, height=45, width=170)
        self.Button2.configure(text='''Mean Shift''')

        self.Button3 = tk.Button(self.Frame1)
        self.Button3.place(relx=0.017, rely=0.437, height=45, width=170)
        self.Button3.configure(text='''Hierarchical''')


        self.Canvas1=tk.Canvas(self.Frame1)
        self.Canvas1.place(relx=0.455,rely=0.4,relheight=0.43,relwidth=0.4)
        self.Canvas1.configure(borderwidth="2")
        self.Canvas1.configure(relief="ridge")
        self.Canvas1.configure(selectbackground="#c4c4c4")

        Canvas12 = FigureCanvasTkAgg(fig,master=self.Canvas1)
        Canvas12.draw()
        Canvas12.get_tk_widget().pack()

        self.Button_k.bind('<Button-1>',partial(self.kmean,Canvas12=Canvas12))



    def kmean(self,e,Canvas12):
        #global Canvas12
        print("hello tk")
        items = ReadData('data.txt');
        items = CutToTwoFeatures(items,2,3);
        #print(items)
        for item in items:
            #a.clear()
            a.scatter(item[0],item[1],c="gray",alpha=0.5,s=10)
            Canvas12.draw()
            #a.pause(0.1)
        k = 3;

        means = CalculateMeans(k,items,Canvas12);
        print (means);
        # a.show();






if __name__ == '__main__':
    vp_start_gui()