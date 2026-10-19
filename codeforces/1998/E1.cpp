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
int n,x,a[N];
int st[N][20];
int getmx(int x,int y){
    return a[x] > a[y] ? x : y;
}
void init(){
    for(int i=1;i<=n;i++) st[i][0] = i;
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j] = getmx(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int ask(int l,int r){
    int t = log(r-l+1)/log(2);
    return getmx(st[l][t],st[r-(1<<t)+1][t]);
}
int ans;
ll sum[N];
void solve(int l,int r){
    if(l > r) return ;
    ans++;
    int mx = ask(l,r);
    if(a[mx] <= sum[r]-sum[mx]) solve(mx+1,r);
    if(a[mx] <= sum[mx-1]-sum[l-1]) solve(l,mx-1);
}
void solve(){
    n = read(); x = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    init();
    ans = 0;
    solve(1,n);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
