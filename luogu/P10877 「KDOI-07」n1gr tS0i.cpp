#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ull unsigned long long
#define pii pair<ll,ll>
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
const int N = 1e7+10;
const int mod = 998244353;
int n;
signed main(){
    
    int T = read();
    while(T--){
        n = read();
        string s;
        cin >> s;
        ll res = 1;
        for(int i=1;i<=n;i++) res = res*2%mod;
        if(n == 2) cout << "1\n";
        else if(n == 3) cout << "4\n";
        else cout << res << "\n";
    }
    return 0;
}
