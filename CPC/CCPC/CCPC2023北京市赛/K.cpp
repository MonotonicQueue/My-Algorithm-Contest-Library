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
const int N = 10100;
const int mod = 1e9+7;
int g[N][4];
int calc(int x){
    int res = 0;
    while(x) res += x % 10,x /= 10;
    return res;
}
void init(int n = 9000){
    for(int i=1;i<=n;i++){
        g[i][0] = i;
        for(int j=1;j<=3;j++) g[i][j] = calc(g[i][j-1]);
    }
}
int len,k,m;
char num[N];
ll f[1010][10100];
ll dfs(int x,int now,bool flag){
    if(now < 0) return 0;
    if(x == 0) return now == 0;
    if(!flag && f[x][now] != -1) return f[x][now];
    ll res = 0; int lim = flag ? num[x]-'0' : 9;
    for(int i=0;i<=lim;i++)
        res = (res+dfs(x-1,now-i,flag&(i==lim)))%mod;
    if(!flag) f[x][now] = res;
    return res;
}
int main(){
    init();
    memset(f,-1,sizeof(f));
    int T = read();
    while(T--){
        scanf("%s",num+1);
        len = strlen(num+1);
        reverse(num+1,num+1+len);
        k = read(); m = read();
        ll ans = 0;
        for(int i=1;i<=9000;i++){
            if(g[i][min(k-1,3)] == m){
                ans = (ans+dfs(len,i,1))%mod;
            } 
        }
        cout << ans << "\n";    
    }
    
	return 0;
}