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
int n,kmp[N];
vector<int> G[N];
char s[N];
int fa[N][22],dep[N];
void dfs(int x){
    for(int i=1;i<=20;i++)
        fa[x][i] = fa[fa[x][i-1]][i-1];
    for(int y : G[x]){
        fa[y][0] = x;
        dep[y] = dep[x]+1;
        dfs(y);
    }
}
int lca(int x,int y){
    if(dep[x] < dep[y]) swap(x,y);
    for(int i=20;~i;i--)
        if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i=20;~i;i--)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i],y = fa[y][i];
    return fa[x][0];
}
int main(){
    scanf("%s",s+1);
    n = strlen(s+1);
	for(int i=2,j=0;i<=n;i++){
        while(j && s[j+1] != s[i]) j = kmp[j];
        if(s[j+1] == s[i]) j++;
        kmp[i] = j;
        // cout << kmp[i] << " ";
    }
    // cout << "\n";
    for(int i=1;i<=n;i++) G[kmp[i]].push_back(i);
    dfs(0);
    int Q = read();
    while(Q--){
        int x = read(),y = read();
        cout << lca(kmp[x],kmp[y]) << "\n";
    }
	return 0;
}
