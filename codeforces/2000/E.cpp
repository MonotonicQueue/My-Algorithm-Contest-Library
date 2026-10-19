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
ll n,m,k,a[N],w;
int id(int x,int y){
    return (x-1)*m+y > 0 ? (x-1)*m+y : 0;
}
ll val[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read(); k = read();
        w = read();
        for(int i=1;i<=w;i++) a[i] = read();
        sort(a+1,a+1+w,greater<ll>());
        for(int i=0;i<=(n+1)*(m+1);i++) val[i] = 0;
        for(int i=k;i<=n;i++)
            for(int j=k;j<=m;j++) val[id(i-k+1,j-k+1)]++,val[id(i+1,j-k+1)]--,val[id(i-k+1,j+1)]--,val[id(i+1,j+1)]++;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) val[id(i,j)] += val[id(i-1,j)]+val[id(i,j-1)]-val[id(i-1,j-1)];
        sort(val+1,val+1+n*m,greater<ll>());    
        // for(int i=1;i<=w;i++) cout << val[i] << " ";
        // cout << "\n";
        ll ans = 0;
        for(int i=1;i<=w;i++) ans += val[i]*a[i];
        cout << ans << "\n";
    }
    return 0;
}
