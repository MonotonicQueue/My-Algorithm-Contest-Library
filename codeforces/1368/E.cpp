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
const int N = 2e5+10;
int n,m,in[N],col[N];
vector<int> G[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        G[i].clear();
        in[i] = col[i] = 0;
    }
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i),col[i] = 1;
    auto work = [&](int x){
        for(int y : G[x]){
            if(col[y] == 3) continue;
            in[y]--;
            if(!in[y]){
                if(!col[y]) col[y] = 1;
                q.push(y);
            }
        }
    };
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(col[x] == 1){
            for(int y : G[x]){
                if(col[y] == 3) continue;
                in[y]--; col[y] = 2;
                if(!in[y]) q.push(y);
            }    
        }else{
            for(int y : G[x]){
                if(col[y] == 3) continue;
                col[y] = 3;
                in[y] = -1; 
                work(y);
                ans.push_back(y);
            }
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}