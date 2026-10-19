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
int n,cnt[N],deg[N];
vector<int> G[N];
bool vis[N],flag;
int stk[N],top;
vector<int> cir;
void dfs(int x,int ft){
    if(vis[x]){
        int z;
        do{
            z = stk[top--];
            cir.push_back(z);
        }while(z != x);
        flag = true;
        return ;
    }
    stk[++top] = x;
    vis[x] = true;
    for(int y : G[x]){
        if(y == ft) continue;
        dfs(y,x);
        if(flag) return ;
    }
    top--;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        int u = read(),v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) deg[i] = G[i].size(),cnt[deg[i]]++;
    int lst = cir.back();
    ll ans = 0;
    for(int x : cir){
        cnt[deg[lst]]--; cnt[deg[x]]--;
        cnt[deg[lst]-1]++; cnt[deg[x]-1]++;
        if(cnt[5] == 0 && cnt[0] == 0){
            ans += cnt[1]+cnt[2]+cnt[3];
        }
        cnt[deg[lst]]++; cnt[deg[x]]++;
        cnt[deg[lst]-1]--; cnt[deg[x]-1]--;
        lst = x;
    }
    cout << ans;
	return 0;
} 
