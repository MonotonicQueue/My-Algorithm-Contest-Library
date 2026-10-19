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
const int N = 4e5+10;
int n,a[N],vis[N];
int pr[N],cnt,f[N];
void init(int n = 4e5){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            vis[i] = i;
            f[i] = i;
            pr[++cnt] = i;
        }
        for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
            vis[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;pr[j]*pr[j]<=i;j++){
            if(i % pr[j] == 0){
                f[i] = max(f[i],f[i-pr[j]]);
                f[i] = max(f[i],f[i-(i/pr[j])]);
            }
        }
    }
}
vector<int> v[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if(vis[a[i]] == a[i]) cnt++;
    if(cnt >= 2) return puts("-1"),void();
    if(cnt == 0) return puts("2"),void();
    int d = 2;
    for(int i=1;i<=n;i++)
        if(vis[a[i]] == a[i]) d = a[i];
    for(int i=1;i<=n;i++){
        if(f[a[i]] < d) return puts("-1"),void();
    }
    cout << d << "\n";
}
int main(){
    init();
	int T = read();
    while(T--) solve();
    return 0;
}
