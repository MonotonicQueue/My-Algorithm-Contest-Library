#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int mod = 998244353;
int n;
ll f[N];
void solve(){
	n = read();
    if(n == 2) return puts("1"),void();
    f[2] = f[3] = 1;
    ll sum = 2;
    for(int i=4;i<=n;i++){
        f[i] = (sum+1)%mod;
        sum = (sum+i*f[i]%mod-1)%mod;
    }
    ll ans = 0;
    for(int i=2;i<=n;i++) ans = (ans+f[i])%mod;
    cout << (ans+mod)%mod << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}