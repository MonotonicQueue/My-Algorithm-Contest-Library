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
int n;
ll k,a[N];
signed main(){
	int T = read();
	while(T--){
		n = read(); k = read();
		for(int i=1;i<=n;i++) a[i] = read();
		int ans = 0;
		int i=1,j=n;
		for(;i<j;){
			if(a[i] < a[j]){
				if(2*a[i] <= k){
					k -= 2*a[i]; a[j] -= a[i];a[i] = 0; i++; ans++; 
				}else if(2*a[i]-1 == k){
					k = 0; a[i] = 0; ans++; break;
				}else break;
			}else if(a[i] > a[j]){
				if(2*a[j] <= k){
					k -= 2*a[j]; a[i] -= a[j];a[j] = 0; j--; ans++; 
				}else break; 
			}else{
				if(2*a[i] <= k){
					k -= 2*a[i]; ans += 2;i++;j--; 
				}else if(2*a[i]-1 == k){
					k = 0; ans++; break;
				}else break;
			}
//			cout << a[i] << " " << a[j] << " " << i << " "<<j << " " << ans << " " << k << "\n";
			if(!k) break;
		}
		if(i == j && a[i] <= k) ans++;
		cout << ans << "\n";
	}
	return 0;
}
///