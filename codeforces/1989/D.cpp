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
    ll a,b;
}d[N],t[N];
bool cmp(node x,node y){
    return x.a-x.b != y.a-y.b ? x.a-x.b < y.a-y.b : x.a < y.a;
}
ll g[N],f[N];
int main(){
    int T = 1;
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++) d[i].a = read();
        for(int i=1;i<=n;i++) d[i].b = read();
        sort(d+1,d+1+n,cmp);
        int top = 1; t[1] = d[1];
        t[0].a = 1e9;
        for(int i=2;i<=n;i++)
            if(d[i].a < t[top].a) t[++top] = d[i];
        int mn = t[top].a,mx = t[1].a;
        for(int i=mn;i<=mx;i++){
            if(i >= t[top-1].a) top--;
            f[i] = f[i-t[top].a+t[top].b]+2;
            g[i] = max(g[i-1],f[i]);
        }
        ll ans = 0;
        for(int i=1;i<=m;i++){
            int c = read();
            if(c > mx){
                ll ct = (c-mx)/(t[1].a-t[1].b)+1;
                ll x = c-ct*(t[1].a-t[1].b);
                ans += ct*2;
                c = x;
            }
            ans += g[c];
        }
        cout << ans << "\n";
    }
	return 0;
}
