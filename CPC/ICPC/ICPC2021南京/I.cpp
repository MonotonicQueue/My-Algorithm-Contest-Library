#include <bits/stdc++.h>
#define int long long
#define mk make_pair
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 5;
int H, n, m;

struct position{
    int x, y;
    bool operator<(const position& rhs) const { return x == rhs.x ? y < rhs.y : x < rhs.x; }
} p[N][2];

struct line{
    int k, b;
    bool operator<(const line& rhs) const { return k == rhs.k ? b < rhs.b : k < rhs.k; }
    bool operator==(const line& rhs) const { return k == rhs.k && b == rhs.b; }
};

map<line,vector<pii > > mp;
int f[N][2][2];

auto cmp = [](const pii& lhs, const pii& rhs){ return p[lhs.fi][lhs.se] < p[rhs.fi][rhs.se]; };

line line1(position pos){
    if(pos.x < pos.y) return line{1, pos.y - pos.x};
    int x = (pos.x - pos.y) % (H << 1);
    if(x == 0) return line{1, 0};
    if(x <= H) return line{0, x};
    else return line{1, ((H << 1) - x)};
}

line line2(position pos){
    int x = (pos.x + pos.y) % (H << 1);
    if(x == 0) return line{1, 0};
    if(x <= H) return line{0, x};
    else return line{1, ((H << 1) - x)};
}

int dp(int i, int j, int k){
    if(f[i][j][k] != -1) return f[i][j][k];
    if(j){
        line l;
        if(k) l = line1(p[i][j]);
        else l = line2(p[i][j]);
        auto ite = upper_bound(mp[l].begin(), mp[l].end(), mk(i, j), cmp);
        if(ite == mp[l].end()) return f[i][j][k] = 1;
        if(line1(p[ite->fi][ite->se]) == l) return f[i][j][k] = dp(ite->fi, ite->se, 1) + 1;
        else return f[i][j][k] = dp(ite->fi, ite->se, 0) + 1;
    }
    else{
        line l1, l2;
        if(k) l1 = line1(p[i][j]), l2 = line2(p[i][j]);
        else l1 = line2(p[i][j]), l2 = line1(p[i][j]);
        auto ite1 = upper_bound(mp[l1].begin(), mp[l1].end(), mk(i, j), cmp);
        auto ite2 = upper_bound(mp[l2].begin(), mp[l2].end(), mk(i, j), cmp);
        f[i][j][k] = 0;
        if(ite1 != mp[l1].end()){
            if(line1(p[ite1->fi][ite1->se]) == l1) f[i][j][k] = max(f[i][j][k], dp(ite1->fi, ite1->se, 1));
            else f[i][j][k] = max(f[i][j][k], dp(ite1->fi, ite1->se, 0));
        }
        if(ite2 != mp[l2].end()){
            if(line1(p[ite2->fi][ite2->se]) == l2) f[i][j][k] = max(f[i][j][k], dp(ite2->fi, ite2->se, 1));
            else f[i][j][k] = max(f[i][j][k], dp(ite2->fi, ite2->se, 0));
        }
        return f[i][j][k];
    }
}

void solve(){
    cin >> H >> n;
    p[0][1] = {0,0}; mp[{1,0}].push_back(mk(0,1));
    for(int i=1;i<=n;i++){
        cin >> p[i][0].x >> p[i][0].y;
        mp[line1(p[i][0])].emplace_back(mk(i,0));
        mp[line2(p[i][0])].emplace_back(mk(i,0));
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> p[i][1].x >> p[i][1].y;
        mp[line1(p[i][1])].emplace_back(mk(i,1));
        mp[line2(p[i][1])].emplace_back(mk(i,1));
    }
    for(auto& i : mp) sort(i.se.begin(),i.se.end(),cmp);
    for(int i=0;i<=max(n, m);i++)
        for(int j=0;j<=1;j++) f[i][j][0] = f[i][j][1] = -1;
    cout << (dp(0,1,1)-1) << '\n';
    mp.clear();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
