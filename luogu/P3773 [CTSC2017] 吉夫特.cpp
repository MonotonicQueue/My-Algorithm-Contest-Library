#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 3e5+10;
const int mod = 1e9+7;
int n;
ll f[N];
signed main(){
	n = read();
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int S = read();
        for(int T=S&(S-1);T;T=S&(T-1)) f[T] = (f[S]+f[T]+1)%mod;
        ans = (ans+f[S])%mod;
    }
    cout << ans;
	return 0;
}

//g++ -std=c++14 -O2 -o 1st 1st.cpp