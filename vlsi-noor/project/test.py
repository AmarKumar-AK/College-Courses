# import os
# import sys

# def fullAdder_tb_gen_1bit(a,b):
#     a=str(a)
#     b=str(b)
#     f=open("fullAdder/fullAdder_tb.v","w")
#     f.write('`include "fullAdder/fullAdder.v"\nmodule top;\nreg a, b, cin;\nwire sum, ca;\n\tfullAdder FA_0(a,b,cin,sum,ca);\ninitial\nbegin\n')
#     f.write("\t#0 a="+a+"; b="+b+" ; cin=0;\n")
#     f.write('end\ninitial\nbegin\n\t$monitor("%d",sum);\nend\nendmodule')
#     f.close()
#     os.system("iverilog fullAdder/fullAdder_tb.v -o fullAdder1")
#     os.system("./fullAdder1")
# fullAdder_tb_gen_1bit(0,1)

##############################################################
# def abc(a,b,c,xx):
#     return a+b*xx+c*xx*xx

# def polyRegression(x,y):
#     who_is_less=min(len(x),len(y))
#     n=len(x)
#     r=[]
#     for i in range(0,n):
#         r.append(i)
#     sum=0
#     for data in x:
#         sum+=data
#     xm=sum/n
#     sum=0
#     n1=len(y)
#     for data in y:
#         sum+=data
#     ym=sum/n1
#     sum=0
#     for data in r:
#         sum+=data*data
#     x2m=sum/n
#     sum=0
#     for data in r:
#         sum+=data*data*data
#     x3m=sum/n
#     sum=0
#     for data in r:
#         sum+=data*data*data*data
#     x4m=sum/n
#     sum=0
#     for i in range(0,who_is_less):
#         sum+=x[i]*y[i]
#     xym=sum/who_is_less
#     sum=0
#     for i in range(0,who_is_less):
#         sum+=x[i]*x[i]*y[i]
#     x2ym=sum/who_is_less

#     sxx=x2m-xm*xm
#     sxy=xym-xm*ym
#     sxx2=x3m-xm*x2m
#     sx2x2=x4m-x2m*x2m
#     sx2y=x2ym-x2m*ym

#     b=(sxy*sx2x2-sx2y*sxx2)/(sxx*sx2x2-sxx2*sxx2)
#     c=(sx2y*sxx-sxy*sxx2)/(sxx*sx2x2-sxx2*sxx2)
#     a=ym-b*xm-c*x2m

#     print("y = {} + {}x + {}x^2".format(a,b,c))

#     print(" Input Approximation ")
#     print("x    y   y1")

#     xit=0
#     xend=n
#     yit=0
#     yend=n1
#     while(xit<xend and yit<yend):
#         print("{}   {}  {}".format(x[xit],y[yit],abc(a,b,c,x[xit])))
#         xit+=1
#         yit+=1

# if __name__ == '__main__':
#     v1=[0,1,2,3,4,5,6,7,8,9,10]
#     v2=[1, 6, 7, 34, 57, 86, 121, 162, 209, 262, 321]
#     polyRegression(v1,v2)

############################################################################
# from modules import *

# import matplotlib.pyplot as plt

# def abc(a,b,c,xx):
#     res1=mul(b,xx)
#     res2=mul(c,xx)
#     res2=mul(res2,xx)
#     res1=Add(res1,a)

#     return Add(res1,res2)

# def polyRegression(x,y):
#     who_is_less=min(len(x),len(y))
#     n=len(x)
#     r=[]
#     for i in range(0,n):
#         r.append(i)
#     sum=0
#     for data in x:
#         sum=Add(sum,data)
#     xm=sum/n
#     sum=0
#     n1=len(y)
#     for data in y:
#         sum=Add(sum,data)
#     ym=sum/n1
#     sum=0
#     for data in r:
#         res=mul(data,data)
#         sum=Add(sum,res)
#     x2m=sum/n
#     sum=0
#     for data in r:
#         res=mul(data,data)
#         res=mul(res,data)
#         sum=Add(res,sum)
#     x3m=sum/n
#     sum=0
#     for data in r:
#         res=mul(data,data)
#         res=mul(res,data)
#         res=mul(res,data)
#         sum=Add(res,sum)
#     x4m=sum/n
#     sum=0
#     l=[]
#     for i in range(0,who_is_less):
#         # sum+=x[i]*y[i]
#         l.append([x[i],y[i]])
#     sum=mac(l,who_is_less)
#     xym=sum/who_is_less
#     sum=0
#     l=[]
#     for i in range(0,who_is_less):
#         l.append([mul(x[i],x[i]), y[i]])
#     sum=mac(l,who_is_less)
#     x2ym=sum/who_is_less

#     sxx=x2m-mul(int(xm),int(xm))

#     sxy=xym-mul(int(xm),int(ym))
#     sxx2=x3m-mul(int(xm),int(x2m))
#     sx2x2=x4m-mul(int(x2m),int(x2m))
#     sx2y=x2ym-mul(int(x2m),int(ym))

#     # b=(sxy*sx2x2-sx2y*sxx2)/(sxx*sx2x2-sxx2*sxx2)
#     b=(mul(sxy,sx2x2)-mul(sx2y,sxx2))/(mul(sxx,sx2x2)-mul(sxx2,sxx2))
#     # c=(sx2y*sxx-sxy*sxx2)/(sxx*sx2x2-sxx2*sxx2)
#     c=(mul(sx2y,sxx)-mul(sxy,sxx2))/(mul(sxx,sx2x2)-mul(sxx2,sxx2))
#     a=ym-mul(b,xm)-mul(c,x2m)

#     # print("y = {} + {}x + {}x^2".format(a,b,c))

#     print(" Input Approximation ")
#     print("x    y   y1")

#     xit=0
#     xend=n
#     yit=0
#     yend=n1
#     while(xit<xend and yit<yend):
#         print("{}   {}  {}".format(x[xit],y[yit],abc(a,b,c,x[xit])))
#         # xit+=1
#         xit=Add(1,xit)
#         # yit+=1
#         yit=Add(1,yit)

#     return a,b,c

# if __name__ == '__main__':
#     v1=[0,1,2,3,4,5,6,7,8,9,10]
#     v2=[1, 6, 17, 34, 57, 86, 121, 162, 209, 262, 321]
#     a,b,c=polyRegression(v1,v2)
    


#     print("\nequation formed from given data set is ")
#     print("y = {} + {}x + {}x^2\n".format(a,b,c))
#     x=input("enter any value of x : ")
#     res1=mul(x,x)
#     res1=mul(c,res1)
#     res2=mul(b,x)
#     res=Add(a,res1)
#     res=Add(res,res2)
#     print("estimated value is : {}".format(res))

#     v1.append(x)
#     v2.append(res)
#     # plotting points as a scatter plot 
#     # plt.scatter(v1, v2, label= "stars", color= "green",  marker= "*", s=30)
#     plt.plot(v1, v2, color='red', linestyle='dashed', linewidth = 3, marker='o', markerfacecolor='blue', markersize=12)
  
#     # x-axis label 
#     plt.xlabel('x - axis') 
#     # frequency label 
#     plt.ylabel('y - axis') 
#     # plot title 
#     plt.title('Graph') 
#     # showing legend 
#     plt.legend() 
    
#     # function to show the plot 
#     plt.show()
#############################################################
# l=[]
# f = open("data_sets.txt","r")
# for data in f.readlines():
#     l.append(data.split())
# m=[]
# for a,b in l:
#     m.append([int(a),int(b)])
# print(m)

# v1=[]
# v2=[]
# for i in range(0,len(m)):
#     v1.append(m[i][0])
#     v2.append(m[i][1])
# print(v1)
# print(v2)
#########################################################
# from modules import *

# sum=16
# n=3
# count=0
# while(sum>=n):
#     sum=subt(sum,n)
#     count=Add(count,1)
# xm=count+sum/n
# print(sum/n)
# xm=Add(count,2.3)
# print(xm)
##################################################################################
from modules import *
import matplotlib.pyplot as plt

def abc(a,b,c,xx):
    res1=mul(b,xx)
    res2=mul(c,xx)
    res2=mul(res2,xx)
    res1=rec_doub(res1,a)

    return rec_doub(res1,res2)


def polyRegression(x,y):
    who_is_less=min(len(x),len(y))
    n=len(x)
    r=[]
    for i in range(0,n):
        r.append(i)

    sum=0
    for data in x:
        sum=rec_doub(sum,data)
    xm=sum/n
    # xm=div(sum,n)
    print("value of xm is {}".format(xm))

    sum=0
    n1=len(y)
    for data in y:
        sum=rec_doub(sum,data)
    ym=sum/n1
    # ym=div(sum,n1)
    print("value of ym is {}".format(ym))

    sum=0
    for data in r:
        res=mul(data,data)
        sum=rec_doub(sum,res)
    x2m=sum/n
    # x2m=div(sum,n)
    print("value of x2m is {}".format(x2m))

    sum=0
    for data in r:
        res=mul(data,data)
        res=mul(res,data)
        sum=rec_doub(res,sum)
    x3m=sum/n
    # x3m=div(sum,n)
    print("value of x3m is {}".format(x3m))

    sum=0
    for data in r:
        res=mul(data,data)
        res=mul(res,data)
        res=mul(res,data)
        sum=rec_doub(res,sum)
    x4m=sum/n
    # x4m=div(sum,n)
    print("value of x4m is {}".format(x4m))

    sum=0
    l=[]
    for i in range(0,who_is_less):
        # sum+=x[i]*y[i]
        l.append([x[i],y[i]])
    sum=mac(l,who_is_less)
    xym=sum/who_is_less
    # xym=div(sum,who_is_less)
    print("value of xym is {}".format(xym))

    sum=0
    l=[]
    for i in range(0,who_is_less):
        l.append([mul(x[i],x[i]), y[i]])
    sum=mac(l,who_is_less)
    x2ym=sum/who_is_less
    # x2ym=div(sum,who_is_less)
    print("value of x2ym is {}".format(x2ym))

    # sxx=x2m-mul(int(xm),int(xm))
    sxx=subt(x2m,mul(int(xm),int(xm)))

    # sxy=xym-mul(int(xm),int(ym))
    sxy=subt(xym,mul(int(xm),int(ym)))
    # sxx2=x3m-mul(int(xm),int(x2m))
    sxx2=subt(x3m,mul(int(xm),int(x2m)))
    # sx2x2=x4m-mul(int(x2m),int(x2m))
    sx2x2=subt(x4m,mul(int(x2m),int(x2m)))
    # sx2y=x2ym-mul(int(x2m),int(ym))
    sx2y=subt(x2ym,mul(int(x2m),int(ym)))

    # b=(sxy*sx2x2-sx2y*sxx2)/(sxx*sx2x2-sxx2*sxx2)
    # b=(mul(sxy,sx2x2)-mul(sx2y,sxx2))/(mul(sxx,sx2x2)-mul(sxx2,sxx2))
    b=(subt(mul(sxy,sx2x2),mul(sx2y,sxx2)))/(subt(mul(sxx,sx2x2),mul(sxx2,sxx2)))
    # b=div((subt(mul(sxy,sx2x2),mul(sx2y,sxx2))),(subt(mul(sxx,sx2x2),mul(sxx2,sxx2))))
    # c=(sx2y*sxx-sxy*sxx2)/(sxx*sx2x2-sxx2*sxx2)
    # c=(mul(sx2y,sxx)-mul(sxy,sxx2))/(mul(sxx,sx2x2)-mul(sxx2,sxx2))
    c=(subt(mul(sx2y,sxx),mul(sxy,sxx2)))/(subt(mul(sxx,sx2x2),mul(sxx2,sxx2)))
    # c=div((subt(mul(sx2y,sxx),mul(sxy,sxx2))),(subt(mul(sxx,sx2x2),mul(sxx2,sxx2))))
    # a=ym-mul(b,xm)-mul(c,x2m)
    res=rec_doub(mul(b,xm),mul(c,x2m))
    a=subt(ym,res)

    # print("y = {} + {}x + {}x^2".format(a,b,c))

    print(" Input Approximation ")
    print("x    y   y1")

    xit=0
    xend=n
    yit=0
    yend=n1
    while(xit<xend and yit<yend):
        print("{}   {}  {}".format(x[xit],y[yit],abc(a,b,c,x[xit])))
        # xit+=1
        xit=Add(1,xit)
        # yit+=1
        yit=Add(1,yit)

    return a,b,c

if __name__ == '__main__':
    l=[]
    f = open("data_sets.txt","r")
    for data in f.readlines():
        l.append(data.split())

    m=[]
    for a,b in l:
        m.append([int(a),int(b)])
    v1=[]
    v2=[]
    for i in range(0,len(m)):
        v1.append(m[i][0])
        v2.append(m[i][1])
    print(v1)
    print(v2)

    # v1=[0,1,2,3,4,5,6,7,8,9,10]
    # v2=[1, 6, 17, 34, 57, 86, 121, 162, 209, 262, 321]
    a,b,c=polyRegression(v1,v2)


    print("\nequation formed from given data set is ")
    print("y = {} + {}x + {}x^2\n".format(a,b,c))
    x=input("enter any value of x : ")
    res1=mul(x,x)
    res1=mul(c,res1)
    res2=mul(b,x)
    res=rec_doub(a,res1)
    res=rec_doub(res,res2)
    print("estimated value is : {}".format(res))

    # v1.append(x)
    # v2.append(res)
    # plt.scatter(v1, v2, label= "stars", color= "green",  marker= "*", s=30)
    plt.plot(v1, v2, color='red', linestyle='dashed', linewidth = 3, marker='*', markerfacecolor='blue', markersize=12)
    # giving label to x axis
    plt.xlabel('x - axis') 
    # giving label to y axis
    plt.ylabel('y - axis') 
    # giving title for the graph
    plt.title('Graph for Polynomial Regression') 
    plt.show()

# amar=10
# print(f"hello {amar}",20)

# print(2.0==2)