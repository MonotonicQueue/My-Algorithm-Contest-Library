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
const int N = 1e6+10;
int n,m;
struct node{
    ll u,v;
}a[N],b[N];
bool cmp(node x,node y){
    return x.u > y.u;
}
int main(){
	// freopen("buy.in","r",stdin);
    // freopen("buy.out","w",stdout);
    n = read(); m = read();
    for(int i=1;i<=n;i++)
        a[i].u = read(),a[i].v = read();
    for(int i=1;i<=m;i++)
        b[i].u = read(),b[i].v = read();
    b[++m] = node{0,0};
    sort(a+1,a+1+n,cmp); sort(b+1,b+1+m,cmp);
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += a[i].u;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i=1,j=1;i<=m;i++){
        while(j <= n && a[j].u >= b[i].u) q.push(a[j].u-a[j].v),j++;
        if(q.empty()) continue;
        if(q.top() < b[i].v) q.pop(),q.push(b[i].v);
    }
    while(!q.empty()) ans -= q.top(),q.pop();
    cout << ans;
    return 0;
}
