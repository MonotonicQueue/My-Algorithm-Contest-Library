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
int n,m,l[N],b[N],c[N],ccc[N];
int f[N];
vector<int> a[N],v[N];
map<int,int> mp;
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        a[i].clear();
        l[i] = read();
        for(int j=1;j<=l[i];j++){
            int x = read();
            a[i].push_back(x);
        }
        mp.clear();
        for(int x : a[i]) mp[x] = 1;
        int lst = -1;
        for(int j=0;;j++){
            if(mp[j] == 0){
                if(lst == -1) lst = j;
                else{
                    b[i] = lst;
                    c[i] = j;
                    break;
                }
            }
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++)
        mx = max(mx,c[i]);
    for(int i=0;i<=mx;i++) f[i] = 0,v[i].clear(),ccc[i] = 0;
    for(int i=1;i<=n;i++){
        ccc[b[i]]++;
        v[b[i]].push_back(c[i]);
    }
    for(int i=mx;~i;i--){
        f[i] = i;
        for(int x : v[i]){
            f[i] = max(f[i],max(f[x],x));
        }
    }
    int maxn = 0;
    ll ans = 1ll*(m-mx)*(mx+1+m)/2;
    if(mx > m) ans = 0;
    for(int i=1;i<=n;i++)
        if(ccc[b[i]] > 1) maxn = max(maxn,f[b[i]]);
        else if(ccc[b[i]] == 1) maxn = max(maxn,b[i]);
    for(int i=0;i<=min(m,mx);i++) ans += max(f[i],maxn);
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
2 50
2 1 2
2 1 2
*/