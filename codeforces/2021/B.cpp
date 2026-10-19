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
int n,x,a[N];
void solve(){
    n = read(); x = read();
    for(int i=1;i<=n;i++) a[i] = read();
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[a[i]]++;
    for(int i=0;;i++){
        if(!mp[i]){
            cout << i << "\n";
            return ;
        }
        if(mp[i] > 1)
            mp[i+x] += mp[i]-1;
    }
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
