#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int mod = 998244353;
int n,m,T,c[N];
ll f[N],a[N],mul[N];
vector<int> G1[N],G2[N];
struct node{
    int type,p;
    ll v;
}b[N];
int in[N];
inline void topsort1(){
    for(int i=1;i<=m;i++) in[i] = 0;
    for(int i=1;i<=m;i++)
        for(int y : G2[i]) in[y]++;
    queue<int> q;
    for(int i=1;i<=m;i++)
        if(!in[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : G2[x]){
            mul[y] = mul[y]*mul[x]%mod;
            in[y]--;
            if(!in[y]) q.push(y);
        }
    }
}
inline void topsort2(){
    for(int i=1;i<=m;i++) in[i] = 0;
    for(int i=1;i<=m;i++)
        for(int y : G1[i]) in[y]++;
    queue<int> q;
    for(int i=1;i<=m;i++)
        if(!in[i]) q.push(i);
    while(!q.empty()){
        int x = q.front(); q.pop();
        ll mul2 = 1;
        for(int y : G1[x]){
            f[y] = (f[y]+f[x]*mul2%mod)%mod;
            mul2 = mul2*mul[y]%mod;
            in[y]--;
            if(!in[y]) q.push(y);
        }
    }
}
int main(){
    // freopen("call.in","r",stdin);
    // freopen("call.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    m = read();
    for(int i=1;i<=m;i++){
        int tp = read();
        b[i].type = tp; mul[i] = 1;
        if(tp == 1) b[i].p = read(),b[i].v = read();
        if(tp == 2) mul[i] = b[i].v = read();
        if(tp == 3){
            int C = read();
            while(C--){
                int u = read();
                G1[i].push_back(u);
                G2[u].push_back(i);
            }
        }
    }
    topsort1();
    T = read();
    for(int i=1;i<=T;i++) c[i] = read();
    ll totmul = 1;
    for(int i=T;i;i--){
        f[c[i]] = (f[c[i]]+totmul)%mod;
        totmul = totmul*mul[c[i]]%mod;
    }
    for(int i=1;i<=n;i++) a[i] = a[i]*totmul%mod;
    for(int i=1;i<=m;i++) reverse(G1[i].begin(),G1[i].end());
    topsort2();
    for(int i=1;i<=m;i++)
        if(b[i].type == 1)
            a[b[i].p] = (a[b[i].p]+b[i].v*f[i]%mod)%mod;
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    return 0;
}