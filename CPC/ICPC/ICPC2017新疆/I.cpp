#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
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
int n,Q,fa[N];
ll d[N];
int get(int x){
    if(fa[x] == x) return x;
    int rt = get(fa[x]);
    d[x] ^= d[fa[x]];
    return fa[x] = rt;
}
bool merge(int u,int v,ll val){
    int x = get(u),y = get(v);
    if(x == y) return (d[u]^d[v]) == val;
    d[x] = d[v]^d[u]^val;
    fa[x] = y;
    return true;
}
void solve(){
    n = read(); Q = read();
    for(int i=2;i<=n;i++){
        int u = read(),v = read();
    }
    for(int i=1;i<=n;i++) fa[i] = i,d[i] = 0;
    int ans = Q;
    for(int i=1;i<=Q;i++){
        int u = read(),v = read(); ll val = read();
        if(ans != Q) continue;
        if(!merge(u,v,val)) ans = i-1;
    }
    cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}