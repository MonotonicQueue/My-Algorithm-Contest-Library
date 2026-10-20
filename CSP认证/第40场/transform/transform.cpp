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
const int M = 1e3+10;
int n,m,k[M];
int calc(int x,int k){
    return ((x*x+k*k)%8)^k;
}
int work(int x,int k){
    int a = (x >> 6);
    x -= (a << 6);
    int b = (x >> 3),c = x-(b << 3);
    return (b << 6)+((c^calc(b,k)) << 3)+(a^calc(c,k));
}
int f[1<<9][M],g[1<<9];
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++) k[i] = read();
    for(int x=0;x<(1<<9);x++){
        f[x][0] = x;
        for(int i=1;i<=m;i++){
            f[x][i] = work(f[x][i-1],k[i]);
        }
        // cout << f[x][m] << "\n";
        g[f[x][m]] = x;
    }
    for(int i=1;i<=n;i++){
        int x = read();
        cout << g[x] << " ";
    }
	return 0;
}