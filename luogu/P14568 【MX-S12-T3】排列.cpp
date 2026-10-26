#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5010;
const int mod = 998244353;
int n,a[N];
bool chk(){
	bool flag2 = false,flag3 = false;
	for(int i=1;i<=n;i++){
		if(a[i] == 2) flag2 = true;
		if(a[i] == 3) flag3 = true;
		if(flag2 && a[i] == 0) return true;
		if(flag3 && a[i] == 1) return true;
	}
	return false;
}
ll f[N];
int main(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(chk()) return puts("0"),0;
	if(a[1] <= 1) f[2] = 1;
	else f[1] = 1;
	for(int i=2;i<=n;i++){
		if(a[i] <= 1){
			for(int i=n+1;i;i--) f[i] = f[i-1];
		}else{
			for(int i=n+1;i;i--) f[i] = (f[i]+f[i+1])%mod;
		}
	}
	ll ans = 0;
	for(int i=1;i<=n+1;i++) ans = (ans+f[i])%mod;
	cout << ans << "\n";
	return 0;
}