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
const int N = 1e7+10;
const int mod = 1e9+7;
int f[N];
void solve(){
    ll n = read(),k = read();
    if(k == 1) cout << n % mod << "\n";
    else{
        f[1] = f[2] = 1;
        for(int i=3;;i++){
            f[i] = (f[i-1]+f[i-2])%k;
            if(!f[i]){
                cout << n%mod*i%mod << "\n";
                return ;
            }
        }
    }
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}
