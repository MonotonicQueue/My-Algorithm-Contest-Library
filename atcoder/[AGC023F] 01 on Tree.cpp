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
const int N = 2e5+10;
const double inf = 1e9;
int n,p[N],a[N],fa[N],cnt0[N],cnt1[N];
priority_queue<pair<double,int> > q;
bool vis[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
ll ans;
inline void merge(int x,int y){
    x = get(x); y = get(y);
    ans += 1ll*cnt1[x]*cnt0[y];
    cnt0[x] += cnt0[y];
    cnt1[x] += cnt1[y];
    fa[y] = x;
}
int main(){
    n = read();
    for(int i=2;i<=n;i++) p[i] = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++){
        fa[i] = i;
        if(a[i]) cnt1[i]++;
        else     cnt0[i]++;
        q.push(mk(a[i] ? -inf : 0.0,i));
    }
    while(!q.empty()){
        int y = q.top().se;
        q.pop();
        if(vis[y] || y == 1) continue;
        vis[y] = true;
        merge(p[y],y);
        int t = get(p[y]);
        q.push(mk(cnt0[t] ? -cnt1[t]*1.0/cnt0[t] : -inf,t));
    }
    cout << ans;
	return 0;
}