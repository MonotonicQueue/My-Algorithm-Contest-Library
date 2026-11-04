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
const int N = 5e5+10;
int n,m,a[N],nxt[N];
int fa[N],siz[N],ans[N];
void solve(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=n;i;i--){
		if(!nxt[a[i]]) fa[i] = i+1;
		else		   fa[i] = nxt[a[i]];
		nxt[a[i]] = i;
	}
	for(int i=1;i<=n;i++){
		siz[i]++;
		siz[fa[i]] += siz[i];
		if(a[fa[i]] != a[i]) ans[a[i]] += siz[i];
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	cout << "\n";
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}
