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
vector<int> v[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read(),v[i].clear();
    int l = 1,r = n;
    for(int i=1;i<=n;i++){
        v[a[i]].push_back(i);
        l = max(l,i-a[i]+1);
        r = min(r,i+a[i]-1);
    }
    int mn = n,mx = 1;
    for(int i=1;i<=n;i++){
        for(int x : v[i]) mx = max(mx,x),mn = min(mn,x);
        if(mx-mn >= i) return puts("0"),void();
    }
    cout << max(r-l+1,0) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 
