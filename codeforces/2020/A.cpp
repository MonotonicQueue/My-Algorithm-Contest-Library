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
const int N = 1e6+10;
int n,k;
ll pw[N];
void solve(){
    n = read(); k = read();
    if(k == 1) cout << n << "\n";
    else{
        pw[0] = 1;
        int pos = 0;
        for(int i=1;i<=30;i++){
            pw[i] = pw[i-1]*k;
            if(pw[i] > n){
                pos = i;
                break;
            }
        }
        int ans = 0;
        for(int i=pos;~i;i--){
            ans += n/pw[i];
            n %= pw[i];
        }   
        cout << ans << "\n";
    }
    
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
