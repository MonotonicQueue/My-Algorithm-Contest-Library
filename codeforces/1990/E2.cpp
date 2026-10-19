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
const int N = 5e3+10;
int n,B,dep[N];
vector<int> G[N];
bool ask(int x){
    cout << "? " << x << endl;
    return read();
}
inline void print(int x){
    cout << "! " << x << endl;
}
void dfs1(int x,int fa){
    dep[x] = 1;
    for(int y : G[x]){
        if(y == fa) continue;
        dfs1(y,x);
        dep[x] = max(dep[x],dep[y]+1);
    }
}
vector<int> v;
void dfs2(int x,int fa){
    v.push_back(x);
    int fr = 0;
    for(int y : G[x]){
        if(y == fa || dep[y] <= B) continue;
        if(!fr) fr = y;
        else if(ask(y)) return dfs2(y,x);
        else B++;
    }
    if(fr) dfs2(fr,x);
}
inline void solve(){
    B = sqrt(n);
    for(int i=2;i<=n;i++)
        if(G[i].size() == 1){
            for(int j=1;j<=B;j++)
                if(ask(i)) return print(i);
            break;
        }
    dfs1(1,0);
    v.clear();
    dfs2(1,0);
    while(!v.empty() && dep[v.back()] <= B) v.pop_back();
    if(v.empty()) return print(1);
    int l = 0,r = v.size()-1;
    while(l < r){
        int mid = (l+r+1) >> 1;
        if(ask(v[mid])) l = mid;
        else r = mid-2,l = l ? l-1 : l;
    }
    print(v[l]);
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++){
            int u = read(),v = read();
            G[u].push_back(v); G[v].push_back(u);
        }
        solve();
    }
    return 0;
}