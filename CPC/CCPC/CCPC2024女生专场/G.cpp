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
int n,s[N],f[N];
ll k,a[N];
ll g[70][2];
ll dfs(int x,bool flag){
    if(x == -1) return 1;
    if(g[x][flag] != -1) return g[x][flag];
    int lim = flag ? (k >> x) & 1 : 1;
    ll res = 0;
    for(int i=0;i<=lim;i++){
        if(f[x] == i || f[x] == -1){
            res += dfs(x-1,(i==lim)&flag);
        }
    }
    return g[x][flag] = res;
}
void solve(){
    n = read(); k = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=0;i<=62;i++) f[i] = -1;
    bool flag = false;
    for(int i=2;i<=n;i++){
        for(int j=62;~j;j--){
            int x = (a[i]>>j)&1,y = (a[i-1]>>j)&1;
            if(x != y){
                if(y == 0){
                    if(f[j] == 0 || f[j] == -1) f[j] = 0;
                    else flag = true;
                }else{
                    if(f[j] == 1 || f[j] == -1) f[j] = 1;
                    else flag = true;
                }
                break;
            }
        }
    }
    if(flag) return puts("0"),void();
    memset(g,-1,sizeof(g));
    cout << dfs(62,1) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}