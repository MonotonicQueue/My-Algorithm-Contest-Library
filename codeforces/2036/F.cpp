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
const int N = 80;
ll f[N][2][2],g[N][2][2],mod,k,now;
bool dfs(int x,bool flag1,bool flag2){
    if(x == -1) return !flag2;
    if(~f[x][flag1][flag2]) return true;
    int lim = (flag1 ? ((now >> x) & 1) : 1);
    ll cnt = 0,sum = 0;
    for(ll i=0;i<=lim;i++){
        bool fff1 = (i==lim)&&flag1,fff2 = flag2;
        if((1ll << x) < mod) fff2 &= ((k >> x) & 1) == i;
        if(dfs(x-1,fff1,fff2)){
            ll ccc = x ? g[x-1][fff1][fff2] : 1;
            cnt += ccc;
            if(x) sum ^= f[x-1][fff1][fff2];
            if(ccc & 1) sum ^= i << x;
        }
    }
    f[x][flag1][flag2] = sum;
    g[x][flag1][flag2] = cnt&1;
    return true;
}
int main(){
    int T = read();
    while(T--){
        ll l = read(),r = read(),i = read();
        k = read(); mod = (1ll << i);
        memset(f,-1,sizeof(f));
        memset(g,-1,sizeof(g));
        now = r;
        dfs(60,1,1);
        ll ans = f[60][1][1];
        memset(f,-1,sizeof(f));
        memset(g,-1,sizeof(g));
        now = l-1;
        dfs(60,1,1);
        ans ^= f[60][1][1];
        cout << ans << "\n";
    }
	return 0;
} 