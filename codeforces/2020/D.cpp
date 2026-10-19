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
const int N = 2e5+114514;
int n,m,a[N][15];
int fa[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x,int y){
    x = get(x); y = get(y);
    if(x == y) return ;
    fa[y] = x;
}
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) fa[i] = i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=10;j++) a[i][j] = 0;
    while(m--){
        int x = read(),d = read(),k = read();
        a[x][d]++;
        a[x+k*d][d]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            if(i > j){
                a[i][j] += a[i-j][j];
                if(a[i-j][j]) merge(i-j,i);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += fa[i] == i;
    cout << ans << "\n";
}
signed main(){
	int T = read();
	while(T--) solve();
    return 0;
}
