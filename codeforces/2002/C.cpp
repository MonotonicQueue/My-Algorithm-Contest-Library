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
int n;
ll xs,ys,xt,yt;

struct node{
    ll x,y;
}a[N];
ll dis(ll x,ll y,ll xx,ll yy){
    return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
bool chk(){
    for(int i=1;i<=n;i++)
        if(dis(xt,yt,a[i].x,a[i].y) <= dis(xs,ys,xt,yt)) return false;
    return true;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i].x = read(),a[i].y = read();
    xs = read(); ys = read();
    xt = read(); yt = read();
    puts(chk() ? "Yes" : "No");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
