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
const int mod = 1e9+7;
int n,a[N],vis[N];
int pr[N],cnt;
void init(int n = 1e6){
    vis[1] = 1;
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[++cnt] = i,vis[i] = i;
        for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
            vis[i*pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
vector<int> v[N];
ll work(int x){
    ll f0 = 1,f1 = 0;
    for(int d : v[x]){
        // cout << x << " " << d << "\n";
        ll g0 = 0,g1 = 0,now = 1;
        for(int i=0;i<=d;i++){
            if(i & 1){
                g0 = (g0+f1*now%mod*x%mod)%mod;
                g1 = (g1+f0*now)%mod;
                now = now*x%mod;
            }else{
                g0 = (g0+f0*now)%mod;
                g1 = (g1+f1*now)%mod;
            }
            // cout <<i << " " <<  g0 << " " << g1 << "\n";
        }
        f0 = g0; f1 = g1;
        
    }
    return f0;
}
int main(){
    init();
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++){
        int lst = 0,cnt = 0;
        while(a[i] != 1){
            int d = vis[a[i]];
            if(d != lst){
                v[lst].push_back(cnt);
                cnt = 0; lst = d;
            }
            cnt++;
            a[i] /= d;
        }
        v[lst].push_back(cnt);
    }
    ll ans = 1;
    for(int i=1;i<=1000000;i++)
        ans = ans*work(i)%mod;
    cout << ans;
	return 0;
}