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
int n,a[N];
void solve(){
    ll ans = 0;
    ll x = 0;
    for(int i=2;i<=n;i++){
        if(a[i] == 1){
            if(a[i-1] == 1) x = 1;
            else return puts("-1"),void();
            continue;
        }
        ll y = ceil(log(log(a[i-1])/log(a[i]))/log(2));
        y += x;
        y = max(y,0ll);
        ans += y;
        x = y;
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        solve();
    }
	return 0;
}
/*
1
9
16 2 4 2 256 2 4 2 8
*/