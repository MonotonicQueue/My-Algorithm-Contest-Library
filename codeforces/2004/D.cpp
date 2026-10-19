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
int n,m,a[N];
string s[N];
int fa[N];
bool chk(int x,int y){
    if(!x || !y) return false;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            if(s[x][i] == s[y][j]) return true;
    return false;
}
int pre[N][4],nxt[N][4];
int get(int x){
    return  x == fa[x] ? x : fa[x] = get(fa[x]);
}
int ccc[N];
int dis(int x,int y){
    return abs(x-y);
}
map<string,int> mpp;
int mp[7];
vector<int> vec[N];
void solve(){
    //模数记得改
    n = read(); int q = read();
    for(int i=1;i<=n;i++) cin >> s[i];
    for(int i=1;i<=n;i++) vec[i].clear();
    mpp["BG"] = 0; mpp["BR"] = 1; mpp["BY"] = 2;
    mpp["GR"] = 3; mpp["GY"] = 4; mpp["RY"] = 5;
    for(int i=0;i<6;i++) mp[i] = 0;
    for(int i=1;i<=n;i++){
        mp[mpp[s[i]]] = i;
        for(int j=0;j<6;j++)
            if(chk(mp[j],i)) vec[i].push_back(mp[j]);
    }
    for(int i=0;i<6;i++) mp[i] = 0;
    for(int i=n;i;i--){
        mp[mpp[s[i]]] = i;
        for(int j=0;j<6;j++)
            if(chk(mp[j],i)) vec[i].push_back(mp[j]);
    }
    // for(int i=1;i<=n;i++,puts(""))
    //     for(int x : vec[i]) cout << x << " ";
    while(q--){
        int l = read(),r = read();
        int ans = 1e9;
        for(int x : vec[l]) for(int y : vec[r])
            if(chk(x,y)) ans = min(ans,dis(l,x)+dis(x,y)+dis(y,r));
        if(ans == 1e9) cout << "-1\n";
        else cout << ans << "\n";
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
