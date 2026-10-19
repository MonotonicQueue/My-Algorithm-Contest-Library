// LUOGU_RID: 166317952
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
const int N = 5e5+10;
ll n,m,a[N];
int main(){
	int T = read();
	while(T--){
		n = read(); m = 0;
		a[++m] = n;
		while(true){
			ll x = n^a[m];
			for(int i=60;~i;i--)
				if(((a[m] >> i) & 1) && !((x >> i) & 1))
					if((x | (1ll << i)) < a[m]) x |= (1ll << i);
			if(x < a[m] && x) a[++m] = x;
			else break;
		}
		cout << m << "\n";
		while(m--) cout << a[m+1] << " ";
		cout << "\n";
	}
	return 0;
}