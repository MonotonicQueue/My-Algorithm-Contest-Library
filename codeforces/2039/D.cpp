#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e5+10;
int n,m,a[N];
void solve(){
	n = read(); m = read();
    for(int i=1;i<=m;i++) a[i] = read();
    sort(a+1,a+1+m);
    vector<int> ans,f(n+1);
    for(int i=2;i<=n;i++){
        if(f[i]) continue;
        for(int j=i;j<=n;j+=i){
            int tmp = j;
            while(tmp % i == 0) f[j]++,tmp /= i;
        }
    }
    for(int i=1;i<=n;i++)
        if(m-f[i] >= 1) ans.emplace_back(a[m-f[i]]);
        else return puts("-1"),void();
    for(int x : ans) cout << x << " ";
    cout << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}