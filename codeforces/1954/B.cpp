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
const int N = 3e5+10;
int n,m,a[N];
void solve(){
	int mn = 1e9,lst = 1;
	for(int i=2;i<=n;i++){
		if(a[i] != a[1]){
			mn = min(min(mn,i-lst),n-i);
			lst = i+1;
		}
	}
	if(mn == 1e9) cout << "-1\n";
	else cout << mn<< "\n";
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		solve();
	}
	return 0;
}
