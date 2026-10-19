#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
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
int n,m,q;
ll a[N],b[N];
bool flag[N];
void solve(){
    n = read(); m = read(); q = read();
    for(int i=1;i<=n;i++) b[i] = m;
    for(int i=1;i<=m;i++) a[i] = flag[i] = 0;
    int cur = 0;
    vector<int> v;
    while(q--){
        int op = read(),x = read();
        if(op == 1){
            cur = x;
            for(int y : v) flag[y] = false;
            v.clear();
        }else{
            int y = read();
            if(y != cur) continue;
            if(flag[x]) continue;
            flag[x] = true;
            if(op == 2){
                a[x] += b[cur];
                b[cur]--;
            }
            v.push_back(x);
        }
    }
    #define pli pair<ll,int>
    vector<pli> vvv;
    for(int i=1;i<=m;i++) vvv.push_back(mk(a[i],i));
    sort(all(vvv),[](pli x,pli y){return x.fi == y.fi ? x.se < y.se : x.fi > y.fi;});
    for(auto it : vvv) cout << it.se << " " << it.fi << "\n";
}
int main(){
    int Q = read();
    while(Q--) solve();
	return 0;
} 


