#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 310;
const int M = 310;
int mod,n;
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
bitset<N> a[N][10],e[N],f[N],g[N][10];
void solve(){
    mod = n = read(); int u = read();
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++) a[i][j].reset();
        e[i].reset();
    }
    for(int i=0;i<n;i++){
        for(int x=0;x<n;x++){
            int c = (fpow(x,i+1)+fpow(u,i+1))%7;
            a[i][c][x] = 1;
        }
    }
    for(int i=0;i<n;i++){
        e[i].reset();
        for(int j=i+1;j<n;j++){
            int cnt = 0;
            for(int k=0;k<7;k++)
                cnt += (a[i][k]&a[j][k]).count();
            if(cnt*2 >= n) e[i][j] = e[j][i] = 1;
        }
    }
    f[0].reset(); int m = 0;
    for(int i=0;i<7;i++) g[0][i].set();
    for(int i=n-1;~i;i--){
        for(int j=0;j<=m;j++){
            if((f[j]&e[i]) == f[j]){
                ++m;
                f[m] = f[j]; f[m][i] = 1;
                int cnt = 0;
                for(int k=0;k<7;k++){
                    g[m][k] = g[j][k] & a[i][k];
                    cnt += g[m][k].count();
                }
                if(cnt*2 < n) m--;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout << e[i][j];
    //     cout << "\n";
    // }
    for(int i=m;~i;i--){
        bool flag = true;
        for(int j=i+1;j<=m;j++)
            if((f[i]&f[j]) == f[i]){
                flag = false;
                break;
            }
        if(flag){
            for(int j=0;j<n;j++)
                if(f[i][j]) cout << j << " ";
            cout << "\n";
        }
    }
    puts("END");
}
int main(){
	int T = read();
	while(T--) solve();
	return 0;
}