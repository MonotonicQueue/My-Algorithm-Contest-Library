#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int dx[8] = {0,0,1,1,-1,-1,1,-1};
const int dy[8] = {1,-1,1,-1,1,-1,0,0};
void solve(){
    int N = read(),M = read();
    // map<pair<int,int>,bool> mp;
    
    vector<pii> mp;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            char c; cin >> c;
            if(c == '#') mp.emplace_back(i,j);
        }
    int mx = mp.size(),tar = 0;
    for(int d=1;d<=321;d++){
        map<pii,pii> v;
        for(auto [x,y] : mp){
            for(int i=0;i<8;i++)
                v[mk(x+dx[i],y+dy[i])].fi++;
            v[mk(x,y)].se = 1;
        }
        vector<pii> q;
        for(auto [p,val] : v){
            if(val.se && val.fi >= 2 && val.fi <= 3) q.push_back(p);
            if(!val.se && val.fi == 3) q.push_back(p);
        }
        mp = q;
        if(mp.size() > mx){
            mx = mp.size();
            tar = d;
        }
    }
    cout << tar << " " << mx << " " << mp.size() << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
3 5
..#
..#
..#
..#
..#
*/