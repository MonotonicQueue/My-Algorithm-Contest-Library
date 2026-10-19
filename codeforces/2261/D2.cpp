#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
int n,m;
vector<int> add[N],del[N];
mt19937_64 rnd(time(0));
ull hsh[N],val[N],lsh[N];
int col[N],vis[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        add[i].clear();
        del[i].clear();
        vis[i] = 0;
    }
    for(int i=1;i<=m;i++){
        int l = read(),r = read();
        add[l].push_back(i);
        del[r].push_back(i);
        hsh[i] = rnd();
    }
    if(n == 1) return puts("0"),void();
    ull now = 0;
    for(int i=1;i<=n;i++){
        for(int x : add[i]) now ^= hsh[x];
        lsh[i] = val[i] = now;
        for(int x : del[i]) now ^= hsh[x];
    }
    sort(lsh+1,lsh+1+n);
    int len = unique(lsh+1,lsh+1+n)-lsh-1;
    for(int i=1;i<=n;i++){
        col[i] = lower_bound(lsh+1,lsh+1+len,val[i])-lsh;
    }
    int lst = 1,tot = 1;
    bool dis = false;
    vector<pii> v;
    for(int i=1;i<=n;i++){
        int c = col[i];
        if(vis[c] == tot){
            v.emplace_back(lst,i-1);
            tot++;
            lst = i;
        }
        vis[c] = tot;
    }
    v.emplace_back(lst,n);
    int S = v.size();
    int k = 0;
    if(S == 1) {
        k = 0;
    }else if(S%2 == 0){
        k = S/2;
    }else{
        int tag = S+1;
        for(int i=v[0].fi;i<=v[0].se;i++) vis[col[i]] = tag;
        dis = true;
        for(int i=v.back().fi;i<=v.back().se;i++)
            if(vis[col[i]] == tag){
                dis = false;
                break;
            }
        k = dis ? S/2 : S/2+1;
    }
    cout << k << '\n';
    if(k == 0) return;
    vector<pii> ev;
    ev.emplace_back(0,1);
    for(int i=1;i<k;i++){
        ev.emplace_back(i,1);
        ev.emplace_back(i-1,0);
    }
    if(S % 2 == 1 && dis)
        ev.emplace_back(k-1,0);
    vector<int> o(k,-1);
    vector<pii> ans;
    for(int i=0;i<S-1;i++){
        int bit = ev[i].fi;
        int flag = ev[i].se;
        int b = v[i].se;
        if(flag){
            o[bit] = b;
        }else{
            ans.emplace_back(o[bit]+1,b);
            o[bit] = -1;
        }
    }
    for(int i=0;i<k;i++)
        if(o[i] != -1) ans.emplace_back(o[i]+1,n);
    for(auto &[l,r] : ans){
        cout << l << ' ' << r << '\n';
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
