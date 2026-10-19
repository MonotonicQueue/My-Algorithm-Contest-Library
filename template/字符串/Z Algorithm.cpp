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
const int N = 2e7+10;
int n,m;
char a[N],b[N];
int Z[N],p[N];
void getZ(){
	Z[1] = m;
	for(int i=2,l=0,r=0;i<=m;i++){
		if(i <= r) Z[i] = min(Z[i-l+1],r-i+1);
		while(i+Z[i] <= m && b[i+Z[i]] == b[1+Z[i]]) Z[i]++;
		if(i+Z[i]-1 > r) r = i+Z[i]-1,l = i;
	}
}
void exkmp(){
	for(int i=1,l=0,r=0;i<=n;i++){
		if(i <= r) p[i] = min(Z[i-l+1],r-i+1);
		while(i+p[i] <= n && a[i+p[i]] == b[1+p[i]]) p[i]++;
		if(i+p[i]-1 > r) r = i+p[i]-1,l = i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> a+1 >> b+1;
	n = strlen(a+1); m = strlen(b+1);
	getZ(); exkmp();
	ll ans = 0;
	for(int i=1;i<=m;i++) ans ^= 1ll*i*(Z[i]+1);
	cout << ans << "\n";
	ans = 0;
	for(int i=1;i<=n;i++) ans ^= 1ll*i*(p[i]+1);
	cout << ans;
	return 0;
}


