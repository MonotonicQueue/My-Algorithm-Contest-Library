#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
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
const int B = 400;
int n,Q,a[N],b[N];
int posa[N],posb[N];
ui f[N],ans[N],suma[N],sumb[N];
int pr[N],cnt,mu[N];
bool vis[N];
void init(int n=1e5){
    mu[1] = 1;
    for(int i=2;i<=n;i++){
        if(!vis[i]) mu[i] = -1,pr[++cnt] = i;
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            vis[i*pr[j]] = true;
            if(i % pr[j] == 0) break;
            mu[i*pr[j]] = -mu[i];
        }
    }
    for(ui i=1;i<=(ui)n;i++)
        for(ui j=1;j*j<=i;j++)
            if(i % j == 0){
                f[i] += j*j*mu[i/j];
                if(j*j != i) f[i] += (i/j)*(i/j)*mu[j];
            }
}
struct Query{int p,op,id;};
vector<Query> q[N];
vector<pair<int,ui>> v[N];
int bel[N];
ui val[N],sum[N];
void add(int x,ui y){
    val[x] += y;
    sum[bel[x]] += y;
}
ui ask(int x){
    ui res = 0;
    for(int i=1;i<bel[x];i++) res += sum[i];
    for(int i=(bel[x]-1)*B+1;i<=x;i++) res += val[i];
    return res;
}
int main(){
    init();
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    for(int i=1;i<=n;i++){
        posa[a[i]] = i;
        posb[b[i]] = i;
    }
    Q = read();
    for(int i=1;i<=Q;i++){
        int l = read(),r = read(),L = read(),R = read();
        q[r].push_back(Query{R,1,i});
        q[r].push_back(Query{L-1,-1,i});
        q[l-1].push_back(Query{R,-1,i});
        q[l-1].push_back(Query{L-1,1,i});
    }
    for(int d=1;d<=B;d++){
        for(int i=1;i<=n;i++){
            suma[i] = suma[i-1]+(a[i] % d == 0);
            sumb[i] = sumb[i-1]+(b[i] % d == 0);
        }
        for(int i=1;i<=n;i++)
            for(auto &[x,op,id] : q[i])
                ans[id] += op*suma[i]*sumb[x]*f[d];
    }
    for(int i=1;i<=n;i++) bel[i] = (i-1)/B+1;
    for(int d=B+1;d<=n;d++)
        for(int i=d;i<=n;i+=d) for(int j=d;j<=n;j+=d)
            v[posa[i]].emplace_back(posb[j],f[d]);
    for(int i=1;i<=n;i++){
        for(auto [x,y] : v[i]) add(x,y);
        for(auto &[x,op,id] : q[i]) ans[id] += op*ask(x);
    }
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
	return 0;
}