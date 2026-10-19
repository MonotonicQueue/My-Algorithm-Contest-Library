#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
const int mod = 998244353;
int n;
ll f[N],g[N];
ll a[N],mn[N],mx[N];
int main(){
	int T = read();
	while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        mn[1] = a[1];
        mx[1] = max(a[1],-a[1]);
        if(mn[1] >= 0) f[1] = g[1] = 2;
        else f[1] = g[1] = 1;
        bool flag = false;
        for(int i=2;i<=n;i++){
            mn[i] = mn[i-1]+a[i];
            mx[i] = max(mx[i-1]+a[i],abs(mn[i]));
            if(mn[i] >= 0) f[i] = 2*f[i-1]%mod;
            else f[i] = f[i-1]%mod;
            if(mx[i-1]+a[i] > abs(mn[i])){
                if(mx[i-1]+a[i] >= 0) g[i] = g[i-1]*2%mod;
                else g[i] = g[i-1];
            }else if(mx[i-1]+a[i] < abs(mn[i])){
                g[i] = f[i];
            }else{
                if(mn[i] != mx[i]) g[i] = (g[i-1]*2+f[i])%mod;
                else g[i] = g[i-1]*2%mod;
            }
        }
        cout << g[n] << "\n";
	}
	return 0;
}
