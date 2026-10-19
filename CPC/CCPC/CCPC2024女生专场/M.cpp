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
const int N = 2e5+10;
int n,p[N],f[N];
void solve(){
    n = read();
    for(int i=2;i<=n;i++) p[i] = read();
    for(int i=1;i<=n;i++) f[i] = 1e9;
    int ans = 0;
    for(int i=n;i>=2;i--){
        if(f[i] == 1e9) f[i] = 0;
        f[p[i]] = min(f[p[i]],f[i]+1);
        ans = max(ans,f[i]+1);
    }
    cout << max(f[1],ans) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}