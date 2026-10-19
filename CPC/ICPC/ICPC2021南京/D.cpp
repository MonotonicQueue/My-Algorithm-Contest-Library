#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e5+10;
int n,a[N];
int t[N],flag[N];
void init(){
	for(int i=1;i<=n;i++) t[i] = flag[i] = 0;
} 
void add(int x,int y){
	flag[x]++;
	if(flag[x] == 1)
		while(x <= n){
			t[x] += y;
			x += x&(-x);
		}
}
int ask(int x){
	int res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(n == 1) return puts("0"),void();
	init();
	cout << "0 ";
	ll sum = 0,mx = a[1],now = 1,s = 0,c = 0;
	for(int i=2;i<=n;i++){
		if(a[i] > mx){
			add(mx,1);
			mx = a[i]; now++;
			s = i-1; c = 0;
		}else{
			add(a[i],1);
			sum += ask(n)-ask(a[i]);
		}
		s += a[i] < mx;
		if(flag[mx]) c += a[i] < mx;
		if(i != n) cout << sum+s+now-1-c << " ";
		else cout << sum+s+now-1-c << "\n";
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
/*

1
11
6 5 10 10 9 2 8 8 5 8 11
*/
