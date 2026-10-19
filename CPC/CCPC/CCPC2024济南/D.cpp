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
const int N = 1100;
const int mod = 998244353;
const int M = 1e7+10;
int n;
struct OPT{
    int a,x,b,y;
    int type;
}a[N];
int sum;
pii f[N][N];
pii dfs(int x,int tp){
    if(f[x][tp] != mk(-1,-1)) return f[x][tp];
    sum++;
    if(sum > 1e7){
        puts("-1");
        exit(0);
    }
    if(tp == 0 && a[x].type == 1) return f[x][tp] = mk(1,0);
    if(a[x].type == 0 && a[x].a == tp) return f[x][tp] = mk(1,a[x].x);
    auto [cnt1,z1] = dfs(a[x].y,a[x].b);
    if(!z1) return f[x][tp] = mk(cnt1+1,z1);
    auto [cnt2,z2] = dfs(z1,tp);
    return f[x][tp] = mk((cnt1+cnt2+1)%mod,z2);
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        char op; cin >> op;
        if(op == 'H'){
            a[i].type = 1;
            a[i].b = read(); a[i].y = read();
        }else{
            a[i].a = read(); a[i].x = read();
            a[i].b = read(); a[i].y = read();
        }
    }
    memset(f,-1,sizeof(f));
    cout << dfs(1,0).fi << "\n";
	return 0;
}