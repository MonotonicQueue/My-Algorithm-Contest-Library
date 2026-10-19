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
const int N = 2e5+10;
int n,p[N][3];
pair<int,int> f[N];
void solve(){
    n = read();
    for(int j=0;j<=2;j++)
        for(int i=1;i<=n;i++) p[i][j] = read();
    for(int i=1;i<=n;i++) f[i] = mk(-1,-1);
    int mn[3] = {n,n,n};
    for(int i=n-1;i;i--){
        int pos = -1;
        for(int j=0;j<=2;j++) if(p[i][j] >= p[mn[j]][j]) pos = j;
        if(pos == -1) continue;
        f[i] = mk(pos,mn[pos]);
        for(int j=0;j<=2;j++) if(p[i][j] <  p[mn[j]][j]) mn[j] = i;
    }
    string s = "qkj";
    if(f[1].fi == -1) return puts("NO"),void();
    puts("YES");
    vector<pair<char,int>> ans;
    int now = 1;
    while(now != n){
        ans.emplace_back(s[f[now].fi],f[now].se);
        now = f[now].se;
    }
    cout << ans.size() << "\n";
    for(auto [u,v] : ans) cout << u << " " << v << "\n";
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}