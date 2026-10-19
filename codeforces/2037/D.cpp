#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;
int n,m,L;
int l[N],r[N];
int x[N],v[N];
void solve(){
	n = read(); m = read(); L = read();
	for(int i=1;i<=n;i++){
		l[i] = read(); r[i] = read();
	}
	int now = 1,ans = 0;
	for(int i=1;i<=m;i++){
		x[i] = read(); v[i] = read();
	}
	priority_queue<int> q;
	for(int i=1,j=1;i<=n;i++){
		while(j <= m && x[j] <= l[i]){
			q.push(v[j]);
			j++;
		}
		int len = r[i]-l[i]+1;
		while(now <= len){
			if(q.empty()) return puts("-1"),void();
			ans++;
			now += q.top();
			q.pop();
		}
	}
	cout << ans << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
