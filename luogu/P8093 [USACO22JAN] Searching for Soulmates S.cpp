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
ll calc(ll a,ll b){
    if(a > b) return 1e18;
    if((a*2) > b) return b-a;
    return (b & 1) ? calc(a,b-1)+1 : calc(a,b>>1)+1;
}
void solve(){
    ll a = read(),b = read();
    ll ans = 1e18,cnt = 0;
    do{
        ll res = calc(a,b);
        ans = min(ans,res+cnt);
        (a & 1) ? a++ : a>>=1;
        cnt++;
    }while(a > 1);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 