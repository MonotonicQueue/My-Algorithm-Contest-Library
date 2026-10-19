#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n;
vector<int> G[N];
int dep[N],st[N][22],dfn[N],fa[N],cnt,Lg[N];
void dfs(int x,int fr){
    dfn[x] = ++cnt;
    fa[x] = fr;
    st[dfn[x]][0] = fa[x];
    dep[x] = dep[fr]+1;
    for(int y : G[x])
        if(y != fr) dfs(y,x);
}
int getmn(int x,int y){
    return dfn[x] < dfn[y] ? x : y;
}
void lca_init(){
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j] = getmn(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    for(int i=2;i<=n;i++) Lg[i] = Lg[i>>1]+1;
}
int lca(int x,int y){
    if(x == y) return x;
    x = dfn[x]; y = dfn[y];
    if(x > y) swap(x,y);
    x++; int t = Lg[y-x+1];
    return getmn(st[x][t],st[y-(1<<t)+1][t]);
}
int dis(int x,int y){
    return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
struct Data{
    int x,y,d;
    Data(int x=0,int y=0,int d=-1): x(x),y(y),d(~d ? d : (x ? dis(x,y) : 0)){}
    bool operator<(const Data&o)const{return d < o.d;}
    Data friend operator+(const Data&x,const Data &y){
        return max(max(x,y),max(max(Data(x.x,y.x),Data(x.x,y.y)),
        max(Data(x.y,y.x),Data(x.y,y.y))));
    }
}f[N][20];
ll ans;
int calc(int l,int r){
    int t = Lg[r-l+1];
    return (f[l][t]+f[r-(1<<t)+1][t]).d;
}
void solve(int l,int r){
    if(l >= r) return ;
    int mid = (l+r) >> 1;
    solve(l,mid); solve(mid+1,r);
    ll sum = 0;
    for(int i=mid+1;i<=r;i++) sum += calc(mid,i);
    ans += sum;
    for(int i=mid-1;i>=l;i--){
        for(int j=mid+1,pl,pr;j<=r;j=pl+1){
            int t = calc(i,j)-calc(i+1,j);
            pl = j,pr = r;
            while(pl < pr){
                int md = (pl+pr+1) >> 1;
                if(calc(i,md)-calc(i+1,md) == t) pl = md;
                else pr = md-1;
            }
            sum += 1ll*t*(pl-j+1);
        }
        ans += sum;
    }
}
int main(){
    n = read();
    for(int i=1;i<n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    lca_init();
    for(int i=1;i<=n;i++) f[i][0] = Data(i,i);
    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = f[i][j-1]+f[i+(1<<(j-1))][j-1];
    solve(1,n);
    cout << ans;
	return 0;
}