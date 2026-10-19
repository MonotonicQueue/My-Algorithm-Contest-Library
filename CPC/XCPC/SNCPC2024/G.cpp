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
const int N = 20;
ll n,num,a[N];
ll f[N][2];
ll dfs(int x,bool flag){
	if(x == -1) return 1;
	if(f[x][flag] != -1) return f[x][flag];
	ll res = 0; int lim = flag ? a[x] : 9;
	for(int i=0;i<=lim;i++){
		if(i == num) continue;
		res += dfs(x-1,flag&&(i==lim));
	}
	return f[x][flag] = res;
}
void solve(){
	n = read(); num = read();
	memset(f,-1,sizeof(f));
	memset(a,0,sizeof(a));
	for(int i=0;n;i++) a[i] = n%10,n /= 10;
	cout << dfs(19,1) << "\n";
}
int main(){
	int T; cin >> T;
	while(T--) solve();
	return 0;
}