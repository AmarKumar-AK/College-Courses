from modules import *
import matplotlib.pyplot as plt

estimated_value=[]
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
        r.append(x[i])

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
        estimated_value.append(abc(a,b,c,x[xit]))
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

    a,b,c=polyRegression(v1,v2)


    print("\nequation formed from given data set is ")
    print("y = {} + {}x + {}x^2\n".format(a,b,c))
    x=int(input("enter any value of x(enter -999 to quit) : "))
    while(x!=-999):
        res1=mul(x,x)
        res1=mul(c,res1)
        res2=mul(b,x)
        res=rec_doub(a,res1)
        res=rec_doub(res,res2)
        print("estimated value is : {}".format(res))
        x=int(input("enter any value of x : "))

    print("estimated value for test data sets")
    print(estimated_value)

    # v1.append(x)
    # v2.append(res)
    # plt.scatter(v1, v2, label= "stars", color= "green",  marker= "*", s=30)
    plt.plot(v1, v2, color='red', linestyle='dashed', linewidth = 3, marker='*', markerfacecolor='blue', markersize=12, label='actual')
    plt.plot(v1, estimated_value, color='green', linestyle='solid', linewidth = 3, marker='.', markerfacecolor='yellow', markersize=12, label='estimated')
    # giving label to x axis
    plt.xlabel('x - axis') 
    # giving label to y axis
    plt.ylabel('y - axis') 
    # giving title for the graph
    plt.title('Graph for Polynomial Regression')
    plt.legend()
    plt.show()

# amar=10
# print(f"hello {amar}",20)

# print(2.0==2)