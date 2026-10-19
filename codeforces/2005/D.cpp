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
int n,a[N],b[N];
struct node{
    int d1,d2;
    ll sum;
};
bool cmp(node x,node y){
    if(x.d1 != y.d1) return x.d1 > y.d1;
    return x.d2 > y.d2;
}
vector<node> v[3];
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    for(int i=0;i<=2;i++) v[i].clear();
    v[0].push_back(node{a[1],b[1],1});
    v[1].push_back(node{b[1],a[1],1});
    for(int i=2;i<=n;i++){
        vector<node> now[3];
        for(auto it : v[0])
            now[0].push_back(node{__gcd(it.d1,a[i]),__gcd(it.d2,b[i]),it.sum}),
            now[1].push_back(node{__gcd(it.d1,b[i]),__gcd(it.d2,a[i]),it.sum});
        for(auto it : v[1])
            now[1].push_back(node{__gcd(it.d1,b[i]),__gcd(it.d2,a[i]),it.sum}),
            now[2].push_back(node{__gcd(it.d1,a[i]),__gcd(it.d2,b[i]),it.sum});
        for(auto it : v[2])
            now[2].push_back(node{__gcd(it.d1,a[i]),__gcd(it.d2,b[i]),it.sum});
        for(int j=0;j<=2;j++) v[j].clear(),sort(now[j].begin(),now[j].end(),cmp);
        for(int j=0;j<=2;j++){
            for(auto it : now[j]){
                if(v[j].empty() || v[j].back().d1 != it.d1 || v[j].back().d2 != it.d2){
                    v[j].push_back(it);
                }else v[j].back().sum += it.sum;
            }
        }
    }
    int mx = 0;
    for(int i=0;i<=2;i++)
        for(auto it : v[i]) mx = max(mx,it.d1+it.d2);
    cout << mx << " ";
    ll ans = 0;
    for(int i=0;i<=2;i++)
        for(auto it : v[i]){
            if(mx == it.d1+it.d2) ans += it.sum;
        }
    int d1 = 0,d2 = 0;
    for(int i=1;i<=n;i++) d1 = __gcd(d1,a[i]);
    for(int i=1;i<=n;i++) d2 = __gcd(d2,b[i]);
    if(d1+d2 == mx) ans--;
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
2
18 13
15 20
*/