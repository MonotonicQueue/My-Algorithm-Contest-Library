#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e4+10;
const int inf = 1e9;
int n,t,R[N],f[N],g[N],now[N];
pii p[N];
void solve(){
    n = read(); t = read();
	for(int i=1;i<=n;i++)
		p[i].fi = read(),R[i] = p[i].se = read();
	sort(p+1,p+1+n); sort(R+1,R+1+n);
	for(int i=1;i<=n;i++) f[i] = R[i],g[i] = inf,now[i] = n;
	for(int i=n;i;i--){
		for(int j=n;R[j]>=p[i].se;j--){
			f[j] -= t;
			while(now[j] > i && f[j] < p[now[j]].fi) f[j] = min(f[j],g[now[j]]),now[j]--;
			if(f[j] < p[i].fi){
				cout << "no\n";
				return ;
			}
			g[i] = min(g[i],f[j]-t);
		}
	}
	cout << "yes\n";
}
int main(){
	solve();
	return 0;
}
