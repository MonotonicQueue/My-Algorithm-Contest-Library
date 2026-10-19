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
const int N = 101010;
int n,m;
struct node{
    int x,t,id;
}a[N];
bool cmp(node x,node y){
    return x.t < y.t;
}
int pos[N];
int f[N],pre[N],suf[N];
int c[N];
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        a[i].x = read();
        a[i].t = read();
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        c[i] = a[i].t;
        pos[a[i].id] = i;
        if(i > 1) f[i] = abs(a[i].x-a[i-1].x)/abs(a[i].t-a[i-1].t);
    }
    for(int i=2;i<=n;i++) pre[i] = max(pre[i-1],f[i]);
    for(int i=n;i;i--) suf[i] = max(suf[i+1],f[i]);
    while(m--){
        int u = read(),v = read();
        u = pos[u];
        int ans = max(pre[u-1],suf[u+2]);
        if(u > 1 && u < n) ans = max(ans,abs(a[u+1].x-a[u-1].x)/(a[u+1].t-a[u-1].t));
        int id = lower_bound(c+1,c+1+n,v)-c;
        for(int i=-10;i<=10;i++){
            int x = id+i;
            if(x == u || x < 1 || x > n) continue;
            ans = max(ans,abs(a[x].x-a[u].x)/abs(a[x].t-v));
        }
        cout << ans << "\n";
    }
    return 0;
}
