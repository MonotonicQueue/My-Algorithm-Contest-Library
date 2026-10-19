#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n,p[N],mxsiz[N],siz[N];
vector<int> G[N];
ll f[N],ans,g[N];
void dfs1(int x,int fa){
    siz[x] = 1;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs1(y,x);
        siz[x] += siz[y];
        mxsiz[x] = max(mxsiz[x],siz[y]);
        f[x] += f[y];
    }
    f[x] += siz[x];
    mxsiz[x] = max(mxsiz[x],n-siz[x]);
}
void dfs2(int x,int fa){
    for(int y : G[x]){
        if(y == fa) continue;
        g[y] = g[x]-siz[y]+n-siz[y];
        dfs2(y,x);
    }
}
ll res;
vector<int> c;
bitset<N> b;
void solve(int n){
    b.reset();
    b[0] = 1;
    for(int y : c)
        b |= b << y;
    res = 0;
    for(int i=0;i<=n;i++)
        if(b[i]) res = max(res,1ll*i*(n-1-i));
}

ll calc(int x){
    if(G[x].size() == 1) return 0;
    if(mxsiz[x] >= n/2) return 1ll*mxsiz[x]*(n-1-mxsiz[x]);
    vector<int> v;
    for(int y : G[x]) if(y != p[x]) v.push_back(siz[y]);
    v.push_back(n-siz[x]);
    sort(all(v));
    int m = v.size(),cnt = 1;
    v.push_back(0);
    c.clear();
    for(int i=1;i<=m;i++){
        if(v[i] != v[i-1]){
            for(int j=0;j<=20;j++)
                if(cnt >= (1<<j)) c.push_back((1<<j)*v[i-1]),cnt -= (1<<j);
            if(cnt) c.push_back(cnt*v[i-1]);
            cnt = 1;
        }else cnt++;
    }
    solve(n);
    return res;
}
int main(){
    n = read();
    for(int i=2;i<=n;i++) p[i] = read();
    for(int i=2;i<=n;i++){
        G[p[i]].push_back(i);
        G[i].push_back(p[i]);
    }
    dfs1(1,0);
    g[1] = f[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++) ans = max(ans,g[i]+calc(i));
    cout << ans;
	return 0;
}