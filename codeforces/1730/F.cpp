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
const int N = 5100;
int n,k,p[N],pos[N];
int f[N][1<<9],g[N][1<<9];
signed main(){
    n = read(); k = read();
	for(int i=1;i<=n;i++) p[i] = read(),pos[p[i]] = i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) g[i][0] += pos[j] < pos[i];
	}
	int S = 1<<(k+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<(1<<k);j++){
			g[i][j] = g[i][0];
			for(int h=0;h<k;h++){
				if(i-h-1 <= 0) break;
				if((j >> h) & 1){
					if(pos[i] > pos[i-h-1]) g[i][j]--;
					else g[i][j]++;
				}
			}
		}
	memset(f,0xcf,sizeof(f));
	f[0][0] = 0;
	for(int i=0;i<=n;i++)
		for(int s=S-1;~s;s--){
			if(f[i][s] < 0) continue;
			for(int j=0;j<=k;j++)
				if((s >> j) & 1)
					f[i][s^(1<<j)] = max(f[i][s^(1<<j)],f[i][s]+g[i-j][s>>(j+1)]); 
			if((s >> k) & 1) continue;
			f[i+1][s<<1|1] = max(f[i+1][s<<1|1],f[i][s]);
		}
	cout << n*(n-1)/2-f[n][0];
    return 0;
}