T = int(input())
def calc(k):
    if(k <= x):
        return a
    elif(k <= x+y):
        return a+(k-x)*b
    else:
        return a+y*b+(k-x-y)*c
for _ in range(T):
    a,b,c,x,y,d = map(int,input().split())
    res = calc(d)
    if(d <= x):
        print(res)
    else:
        res = min(res,a*((d+x-1)//x))
        t = d//x-1
        res = min(res,a*t+calc(d-t*x))
        if(d <= x+y):
            print(res)
        else:
            t = d//(x+y)
            res = min(res,t*(a+y*b)+calc(d-t*(x+y)))
            t -= 1
            res = min(res,t*(a+y*b)+calc(d-t*(x+y)))
            t = (d-x)//(x+y)
            res = min(res,a+t*(a+y*b)+calc(d-x-(x+y)*t))
            t = (d+x+y-1)//(x+y)
            tmp = t*(x+y)-d
            if(tmp <= t*y):
                res = min(res,t*(a+y*b)-tmp*b)
            t = d//x
            tmp = d-t*x
            if(tmp <= t*y):
                res = min(res,t*a+tmp*b)
            print(res)
