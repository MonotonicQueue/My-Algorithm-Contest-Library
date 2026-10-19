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
ll f[70][70][2][2];
ll dfs(int x,int now,bool flag,bool lst,ll mid){
    if(x == -1) return now == 0;
    if(f[x][now][lst][flag] != -1) return f[x][now][lst][flag];
    
    int lim = flag ? ((mid >> x) & 1) : 1;
    ll res = 0;
    for(int i=0;i<=lim;i++)
        res += dfs(x-1,now^((i != lst)*x),flag&(lim==i),i,mid);
    return f[x][now][lst][flag] = res;
}
ll calc(ll mid){
    memset(f,-1,sizeof(f));
    return dfs(62,0,1,0,mid)-1;
}
void solve(){
    ll k = read();
    ll l = 1,r = 4e18,res = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(calc(mid) >= k) res = mid,r = mid-1;
        else l = mid+1;
    }
    ll ans = res%998244353ll;
    cout << ans << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
	return 0;
}