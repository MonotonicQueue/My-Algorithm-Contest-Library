#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
ll n,idx[N],idy[N];
ll x[N],y[N],sumx[N],sumy[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        ll xx = read(),yy = read();
        sumx[i] = x[i] = xx+yy;
        sumy[i] = y[i] = xx-yy;
    }
    sort(sumx+1,sumx+1+n); sort(sumy+1,sumy+1+n);
    for(int i=1;i<=n;i++){
        idx[i] = lower_bound(sumx+1,sumx+1+n,x[i])-sumx;
        idy[i] = lower_bound(sumy+1,sumy+1+n,y[i])-sumy;
    }
    for(int i=1;i<=n;i++) sumx[i] += sumx[i-1],sumy[i] += sumy[i-1];
    ll ans = 1e18;
    for(int i=1;i<=n;i++)
        ans = min(ans,(idx[i]-1)*x[i]-sumx[idx[i]-1]-(n-idx[i])*x[i]+sumx[n]-sumx[idx[i]]+
                      (idy[i]-1)*y[i]-sumy[idy[i]-1]-(n-idy[i])*y[i]+sumy[n]-sumy[idy[i]]);
    cout << ans/2;
    return 0;
}
