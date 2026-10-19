#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10;
int n,m,k,c;
ull a[N];
bool flag[N];
ull ans = 1;
bool chk(int x){
	ll c = 1ll<<x;
	for(int i=1;i<=n;i++)
		if(a[i] & c) return true;
	return false;
}
int main(){
	n = read(); m = read();
	c = read(); k = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++){
		int p = read(),q = read();
		flag[p] = true;
	}
	int sum = 0;
	for(int i=0;i<k;i++)
		if(!flag[i] || chk(i))
			ans *= 2,sum++;
	if(sum == 64 && !n) cout << "18446744073709551616";
	else cout << ans-n;
	return 0;
} 