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
const int N = 1e5+10;
const int mod = 1e9+7;
int n;
ll inv[N],s[N];
int main(){
    n = read();
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    // for(int i=1;i<=n;i++) cout << inv[i]*i%mod << " ";
    // cout << "\n";
    for(int i=1;i<=n;i++) s[i] = (s[i-1]+inv[i])%mod;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll val = read();
        ans = (ans+val*(s[i]+s[n-i+1]-1)%mod)%mod;
    }
    for(int i=1;i<=n;i++) ans = ans*i%mod;
    cout << ans;
	return 0;
}
