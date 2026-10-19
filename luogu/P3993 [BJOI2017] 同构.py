import math
mod = int(1e9+7)
n = 266
def C(n,m):
    if n < m or m < 0:
        return 0
    res = 1
    for i in range(m):
        res = res*(n-i)//(i+1)
    return res
f = h = [0 for i in range(n+1)]
g = [[0 for j in range(n+1)] for i in range(n+1)]
g[0][0] = 1
for i in range(1,n+1):
    h[i] = g[i-1][i-1]
    for j in range(n+1):
        for k in range(j//i+1):
            g[i][j] = g[i][j]+g[i-1][j-k*i]*C(h[i],k)
for i in range(n+1):
    if i % 2 == 1:
        f[i] = g[(i-1)//2][i-1]
    else:
        f[i] = g[i//2-1][i-1]+C(g[i//2-1][i//2-1],2)
T = int(input())
for ttt in range(T):
    m = int(input())
    if m == 1:
        print(0)
    elif m <= 5:
        print(-1)
    elif m == 6:
        print(9)
    else:
        ans = m*(m-1)//2-m
        for i in range(1,n+1):
            if(i > m):
                break
            k = min(h[i],m//i)
            m -= k*i
            ans += k
        print(ans%mod)
