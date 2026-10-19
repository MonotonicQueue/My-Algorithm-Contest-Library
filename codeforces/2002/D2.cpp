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
const int N = 3e5+10;
int n,a[N],p[N],siz[N];
mt19937_64 rnd(time(0));
ull val[N][6],sum[N][6];
struct BIT{
    ull t[N];
    void clear(){
        for(int i=1;i<=n;i++) t[i] = 0;
    }
    void add(int x,ull y){
        if(x > n) return ;
        while(x <= n){
            t[x] += y;
            x += x&(-x);
        }
    }
    ull ask(int x){
        ull res = 0;
        while(x){
            res += t[x];
            x -= x&(-x);
        }
        return res;
    }
    ull query(int l,int r){
        return ask(min(r,n))-ask(l-1);
    }
}T[6],TT[6];
void solve(){
    n = read(); int Q = read();
    for(int i=2;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) p[i] = read();
    for(int i=0;i<6;i++) TT[i].clear();
    for(int i=1;i<=n;i++) sum[i][0] = val[i][0] = i,siz[i] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<5;j++) sum[i][j] = val[i][j] = rnd();
    for(int i=n;i;i--) siz[a[i]] += siz[i];
    for(int i=n;i;i--)
        for(int j=0;j<5;j++) sum[a[i]][j] += sum[i][j];
    ull hsh[6] = {0,0,0,0,0,0},now[6] = {0,0,0,0,0,0};
    for(int i=0;i<5;i++) T[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++) T[j].add(i,val[p[i]][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)
            now[j] += val[p[i]][j]*T[j].query(i,i+siz[p[i]]-1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++) TT[j].add(i,val[p[i]][j]),TT[j].add(i+siz[p[i]],-val[p[i]][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++) hsh[j] += val[i][j]*sum[i][j];
    auto chk = [&]()->bool{
        for(int i=0;i<5;i++)
            if(now[i] != hsh[i]) return false;
        return true;
    };
    
    while(Q--){
        int u = read(),v = read();
        for(int j=0;j<5;j++) now[j] -= val[p[u]][j]*T[j].query(u,u+siz[p[u]]-1);
        for(int j=0;j<5;j++) now[j] -= val[p[v]][j]*T[j].query(v,v+siz[p[v]]-1);
        for(int j=0;j<5;j++) TT[j].add(u,-val[p[u]][j]),TT[j].add(u+siz[p[u]],val[p[u]][j]);
        for(int j=0;j<5;j++) TT[j].add(v,-val[p[v]][j]),TT[j].add(v+siz[p[v]],val[p[v]][j]);
        for(int j=0;j<5;j++) now[j] -= val[p[u]][j]*TT[j].ask(u),now[j] -= val[p[v]][j]*TT[j].ask(v);
        for(int j=0;j<5;j++) T[j].add(u,-val[p[u]][j]),T[j].add(v,-val[p[v]][j]);
        
        swap(p[u],p[v]);
        for(int j=0;j<5;j++) now[j] += val[p[u]][j]*TT[j].ask(u),now[j] += val[p[v]][j]*TT[j].ask(v);
        for(int j=0;j<5;j++) TT[j].add(u,val[p[u]][j]),TT[j].add(u+siz[p[u]],-val[p[u]][j]);
        for(int j=0;j<5;j++) TT[j].add(v,val[p[v]][j]),TT[j].add(v+siz[p[v]],-val[p[v]][j]);
        for(int j=0;j<5;j++) T[j].add(u,val[p[u]][j]),T[j].add(v,val[p[v]][j]);
        for(int j=0;j<5;j++) now[j] += val[p[u]][j]*T[j].query(u,u+siz[p[u]]-1);
        for(int j=0;j<5;j++) now[j] += val[p[v]][j]*T[j].query(v,v+siz[p[v]]-1);
        
        puts(chk() ? "Yes" : "No");
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}