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
int n,f[N];
vector<int> G[N];
void dfs(int x,int fa){
    if(G[x].size() == 1) f[x] = 2;
    else{
        for(int y : G[x]){
            if(y == fa) continue;
            dfs(y,x);
            if(f[y] >= 2) f[x]++;
        }    
    }
}
int main(){
    n = read();
    for(int i=2;i<=n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    puts(f[1] >= 2 ? "You win, temporarily." : "Wasted.");
	return 0;
}