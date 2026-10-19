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
const int N = 1e5+10;
int n,m,dx,dy;
char s[N];
namespace Sub1{
void solve(){
    int x = 0,y = 0;
    map<pii,bool> a;
    a[mk(x,y)] = 1;
    for(int i=1;i<=n;i++){
        if(s[i] == 'W') x--;
        if(s[i] == 'E') x++;
        if(s[i] == 'S') y--;
        if(s[i] == 'N') y++;
        a[mk(x,y)] = 1;
    }
    int ans = 0;
    for(auto [P,w] : a){
        auto [x,y] = P;
        if(a.count(mk(x+1,y)) && a.count(mk(x,y+1)) && a.count(mk(x+1,y+1)))
            ans++;
    }
    cout << ans << "\n";
}
}
namespace Sub2{
void solve(){
    map<pii,vector<pii>> mp;
    mp[mk(0,0)].emplace_back(1,m);
    for(int i=1;i<=n;i++){
        static int x = 0,y = 0;
        if(s[i] == 'W') x--;
        if(s[i] == 'E') x++;
        if(s[i] == 'S') y--;
        if(s[i] == 'N') y++;
        int d = x/dx;
        int ax = x-d*dx,ay = y-d*dy;
        if(ax < 0) ax += dx,ay += dy,d--;
        mp[mk(ax,ay)].emplace_back(d+1,d+m);
    }
    for(auto &[_,v] : mp){
        sort(v.begin(),v.end());
        int L = -1e9,R = -1e9-1;
        vector<pii> V;
        for(auto [l,r] : v){
            if(L == -1e9){
                L = l,R = r;
                continue;
            }
            if(l > R){
                V.emplace_back(L,R);
                L = l; R = r;
            }else R = max(R,r);
        }
        V.emplace_back(L,R);
        v = V;
    }
    auto chk = [&](int x,int y)->bool{
        if(x+1 < dx) return mp.count(mk(x,y)) && mp.count(mk(x+1,y))
                && mp.count(mk(x,y+1)) && mp.count(mk(x+1,y+1));
        else return mp.count(mk(x,y)) && mp.count(mk(x+1-dx,y-dy))
                && mp.count(mk(x,y+1)) && mp.count(mk(x+1-dx,y+1-dy));
    };
    ll ans = 0;
    for(auto [_,v] : mp){
        auto [x,y] = _;
        if(!chk(x,y)) continue;
        auto merge = [&](vector<pii> v1,vector<pii> v2){
            vector<pii> res;
            auto it = v2.begin();
            for(auto [l,r] : v1){
                while(it != v2.end()){
                    while(it != v2.end() && it->se < l) it++;
                    if(it == v2.end()) break;
                    if(it->fi > r) break;
                    res.emplace_back(max(l,it->fi),min(r,it->se));
                    it++;
                }
            }
            return res;
        };
        auto get = [&](pii x){
            if(x.fi < dx) return mp[x];
            x.fi -= dx; x.se -= dy;
            vector<pii> res = mp[x];
            for(auto &[l,r] : res) l--,r--;
            return res;
        };
        v = merge(v,get(mk(x+1,y)));
        v = merge(v,get(mk(x,y+1)));
        v = merge(v,get(mk(x+1,y+1)));
        for(auto [l,r] : v) ans += r-l+1;
    }
    cout << ans << "\n";
}
}
void solve(){
    n = read(); m = read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i] == 'W') dx--;
        if(s[i] == 'E') dx++;
        if(s[i] == 'S') dy--;
        if(s[i] == 'N') dy++;
    }
    if(dx == 0){
        if(dy == 0) return Sub1::solve();
        else{
            for(int i=1;i<=n;i++){
                if(s[i] == 'W') s[i] = 'S';
                else if(s[i] == 'E') s[i] = 'N';
                else if(s[i] == 'S') s[i] = 'W';
                else if(s[i] == 'N') s[i] = 'E';
            }
            swap(dx,dy);
        }
    }
    if(dx < 0){
        for(int i=1;i<=n;i++){
            if(s[i] == 'W') s[i] = 'E';
            else if(s[i] == 'E') s[i] = 'W';
        }
        dx = -dx;
    }
    if(dy < 0){
        for(int i=1;i<=n;i++){
            if(s[i] == 'S') s[i] = 'N';
            else if(s[i] == 'N') s[i] = 'S';
        }
        dy = -dy;
    }
    Sub2::solve();
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}