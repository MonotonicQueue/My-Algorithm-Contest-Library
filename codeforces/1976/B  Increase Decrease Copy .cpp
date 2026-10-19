#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
ll n,a[N],b[N];
int main(){
	int T = read();
    while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n+1;i++) b[i] = read();
		ll cnt1 = 0,cnt2 = 0;
		for(int i=1;i<=n;i++){
			if(a[i] >= b[i]) cnt1 += a[i]-b[i];
			else 			 cnt2 += b[i]-a[i];
		}
		ll minn = 1e18;
		for(int i=1;i<=n;i++){
			ll res = 0;
			if((a[i] <= b[n+1] && b[n+1] <= b[i]) || (b[i] <= b[n+1] && b[n+1] <= a[i])) res = 0;
			else res = min(abs(a[i]-b[n+1]),abs(b[i]-b[n+1]));
			minn = min(minn,res);
		}
		cout << cnt1+cnt2+minn+1 << "\n";
	}
	return 0;
}

