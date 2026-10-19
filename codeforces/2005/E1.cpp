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
const int N = 1500+10;
int l,m,n,a[N];
int b[N][N];
vector<pii> v[N];
int mp[N][N][2];
void add(int x,int y,int c){
    mp[x][y][c]++;
    mp[1][y][c]--;
    mp[x][1][c]--;
    mp[1][1][c]++;
}
void solve(){
    l = read(); n = read(); m = read();
    for(int i=1;i<=l;i++) a[i] = read();
    for(int i=1;i<=7;i++) v[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) b[i][j] = read(),v[b[i][j]].push_back(mk(i,j));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) mp[i][j][0] = mp[i][j][1] = 0;
    int ans = 0;
    for(int I=l;I;I--){
        int c = I&1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) mp[i][j][c] = 0;
        for(auto it : v[a[I]])
            if(!mp[it.fi][it.se][c^1]){
                add(it.fi,it.se,c);
                if(I == 1) ans = 1;
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) mp[i][j][c] += mp[i-1][j][c]+mp[i][j-1][c]-mp[i-1][j-1][c];
    }
    puts(ans ? "T" : "N");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
/*
1
2 2 4
1 2
1 2 3 1
4 1 5 1
*/