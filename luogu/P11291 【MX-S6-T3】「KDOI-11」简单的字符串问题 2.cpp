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
const int N = 5e5+10;
const int mod1 = 1e9+9,mod2 = 998244353;
int n,m,K;
ll hsh1[12][N][2],hsh2[N][2];
ll P=131,pw1[N],pw2[N];
ll gethsh(int l,int r,int op){
    if(op == 0) return (hsh2[l][op]-hsh2[r+1][op]*pw1[r-l+1]%mod1+mod1)%mod1;
    else        return (hsh2[l][op]-hsh2[r+1][op]*pw2[r-l+1]%mod2+mod2)%mod2;
}
char s[12][N],t[N];
int nxt[N],mx[N][20],Lg[N],dep[N];
int getmx(int x,int y){
    return nxt[x] > nxt[y] ? x : y;
}
void init(){
    for(int i=1;i<=m;i++) mx[i][0] = i;
    for(int j=1;j<=19;j++)
        for(int i=1;i+(1<<j)-1<=m;i++)
            mx[i][j] = getmx(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
}
int ask(int l,int r){
    r = min(r,m);
    int t = Lg[r-l+1];
    return getmx(mx[l][t],mx[r-(1<<t)+1][t]);
}
ull ans1,ans2[N],g[N],h[N];
void work1(){
    pw1[0] = pw2[0] = 1;
    for(int i=1;i<=500000;i++){
        pw1[i] = pw1[i-1]*P%mod1;
        pw2[i] = pw2[i-1]*P%mod2;
    }
    for(int i=2;i<=500000;i++) Lg[i] = Lg[i>>1]+1;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        int len = strlen(s[i]+1);
        for(int j=1;j<=len;j++){
            hsh1[i][j][0] = (hsh1[i][j-1][0]+pw1[j-1]*s[i][j])%mod1;
            hsh1[i][j][1] = (hsh1[i][j-1][1]+pw2[j-1]*s[i][j])%mod2;
        }
    }
    scanf("%s",t+1);
    m = strlen(t+1);
    for(int i=m;i;i--){
        hsh2[i][0] = (hsh2[i+1][0]*P+t[i])%mod1;
        hsh2[i][1] = (hsh2[i+1][1]*P+t[i])%mod2;
    }
    for(int i=1;i<=m;i++){
        int l = i,r = m,res = -1;
        auto chk = [&](int mid)->bool{
            for(int j=1;j<=n;j++)
                if(gethsh(i,mid,0) == hsh1[j][mid-i+1][0] &&
                   gethsh(i,mid,1) == hsh1[j][mid-i+1][1]) return true;
            return false;
        };
        while(l <= r){
            int mid = (l+r) >> 1;
            if(chk(mid)) res = mid,l = mid+1;
            else r = mid-1;
        }
        nxt[i] = res;
    }
    init();
}
int fa[N][20]; ll sum[N][20];
vector<int> G[N];
void dfs(int x){
    dep[x] = dep[fa[x][0]]+1;
    for(int i=1;i<=19;i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    sum[x][0] = nxt[fa[x][0]];
    for(int i=1;i<=19;i++) sum[x][i] = sum[x][i-1]+sum[fa[x][i-1]][i-1];
    for(int y : G[x]) dfs(y);
    int t = x;
    ll res = nxt[x]-1ll*K*(x-1);
    for(int i=19;~i;i--){
        if(((K-1) >> i) & 1){
            res += sum[t][i];
            t = fa[t][i];
        }
    }
    ans1 += res;
    ans2[x] += res; g[x+1] -= K;
    h[x]++;
    if(fa[t][0] != t) h[fa[t][0]]--;
    else{
        h[t] += K-dep[x];
    }
}
void dfs1(int x){
    for(int y : G[x]){
        dfs1(y);
        h[x] += h[y];
    }
}
void work2(){
    for(int i=1;i<=m;i++){
        if(nxt[i] == -1){
            fa[i][0] = -1;
            continue;
        }
        int x = ask(i,nxt[i]+1);
        fa[i][0] = x;
        if(x != i) G[x].push_back(i);
    }
    for(int i=1;i<=m;i++)
        if(fa[i][0] == i) dfs(i),dfs1(i);
    for(int i=1;i<=m;i++)
        if(nxt[i] != -1) g[nxt[i]+2] += h[i];
    for(int i=1;i<=m;i++) g[i] += g[i-1],ans2[i] += g[i];
    for(int i=1;i<=m;i++) ans2[i] += ans2[i-1];
    cout << ans1 << "\n";
    for(int i=1;i<=m;i++) cout << ans2[i] << " ";
    cout << "\n";
}
int main(){
    int id = read();
    n = read(); K = read();
    work1(); work2();
	return 0;
}