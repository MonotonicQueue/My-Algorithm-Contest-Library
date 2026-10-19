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
int n,q,a[N];
mt19937_64 rnd(time(0));
ull hsh[N],sum[N];
void solve(){
    n = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]^hsh[a[i]];
    while(q--){
        int l = read(),r = read();
        if(sum[r] == sum[l-1]) puts("YES");
        else puts("NO");
    }
}
int main(){
    for(int i=1;i<=1000000;i++) hsh[i] = rnd();
    int T = read();
    while(T--) solve();
    return 0;
}
