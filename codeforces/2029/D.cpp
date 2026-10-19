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
int n,m,fa[N];
set<int> s[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    if(x == y) return ;
    fa[x] = y;
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) s[i].clear(),fa[i] = i;
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        s[u].insert(v);
        s[v].insert(u);
    }
    set<pii> t;
    set<int> tt;
    for(int i=1;i<=n;i++){
        if(s[i].size() >= 1) t.insert(mk(s[i].size(),i));
    }
    vector<tuple<int,int,int>>ans;
    while(!t.empty()){
        int x = t.rbegin()->se; t.erase(mk(s[x].size(),x));
        if(s[x].size() <= 1) break;
        int fi = 0,se = 0;
        for(int y : s[x]){
            if(!fi) fi = y;
            else{
                se = y;
                break;
            }
        }
        // cout << x << " " << fi << " " << se << "\n";
        if(s[fi].size() >= 1) t.erase(mk(s[fi].size(),fi));
        if(s[se].size() >= 1) t.erase(mk(s[se].size(),se));

        s[x].erase(fi); s[x].erase(se);
        s[fi].erase(x); s[se].erase(x);
        if(s[fi].find(se) != s[fi].end()) s[fi].erase(se),s[se].erase(fi);
        else s[fi].insert(se),s[se].insert(fi);
        if(s[x].size() >= 1) t.insert(mk(s[x].size(),x));
        if(s[fi].size() >= 1) t.insert(mk(s[fi].size(),fi));
        if(s[se].size() >= 1) t.insert(mk(s[se].size(),se));
        ans.emplace_back(x,fi,se);
    }
    for(auto &[x,y] : t) tt.insert(y);
    // for(int y : tt) cout << y << "\n";
    vector<int> v;
    for(int i=1;i<=n;i++)
        if(s[i].size() == 0) v.push_back(i);
    for(int i=1;i<=n;i++){
        for(int x : s[i]) merge(i,x);
    }
    if(!tt.empty()){
        auto work = [&](int x,int y,int z){
            s[y].erase(z); s[z].erase(y);
            s[x].insert(y); s[x].insert(z);
            s[y].insert(x); s[z].insert(x);
            ans.emplace_back(x,y,z);
            merge(x,y);
        };
        for(int x : v){
            int y = *tt.begin();
            int z = *s[y].begin();
            work(x,y,z);
            tt.insert(x);
        }
        for(int i=2;i<=n;i++){
            int x = get(1);
            if(x != get(i)){
                int y = get(i);
                assert(s[y].size());
                int z = *s[y].begin();
                work(x,y,z);
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto &[x,y,z] : ans) cout << x << " " << y << " " << z << "\n";
}
int main(){
	int T = read();
    while(T--) solve();
    return 0;
}
/*
1
6 6
1 2
1 6
4 5
3 4
4 6
3 6
*/