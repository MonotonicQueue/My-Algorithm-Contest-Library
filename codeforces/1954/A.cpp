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
const int N = 1e5+10;
int n,m,k;
int main(){
	int T = read();
	while(T--){
		n = read(); m = read(); k = read();
		if(m == 1) puts("NO");
		else{
			int p = (n-1)/m+1;
			if(n-p <= k) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
