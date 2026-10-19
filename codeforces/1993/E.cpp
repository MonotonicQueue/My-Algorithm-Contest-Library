#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 20;
const int inf = 1e9;
int n,m,a[N][N];
int w[N][N],fc[N][N],fr[N][N];
int f[N][1<<16];
int main(){
	int T = read();
	while(T--){
        n = read(); m = read();
        auto clear = [&](){
            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++) a[i][j] = 0,fc[i][j] = fr[i][j] = inf;
        };
        clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                a[i][j] = read();
                a[i][m] ^= a[i][j];
                a[n][j] ^= a[i][j];
                a[n][m] ^= a[i][j];
            }
        // for(int i=0;i<=n;i++) cout << a[i][m] << "\n";
        int sn = (1<<(n+1))-1,sm = (1<<(m+1))-1;
        for(int rmv=0;rmv<=m;rmv++){
            for(int i=0;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    w[i][j] = 0;
                    for(int l=0;l<=m;l++){
                        if(l == rmv) continue;
                        w[i][j] += abs(a[i][l]-a[j][l]);
                    }
                    w[j][i] = w[i][j];
                }
            for(int i=0;i<=n;i++){
                for(int j=0;j<=sn;j++) f[i][j] = inf;
                f[i][1<<i] = 0;
            }
            for(int s=0;s<=sn;s++){
                for(int i=0;i<=n;i++){
                    if(!((s >> i) & 1)) continue;
                    for(int j=0;j<=n;j++){
                        if((s >> j) & 1) continue;
                        f[j][s|(1<<j)] = min(f[j][s|(1<<j)],f[i][s]+w[i][j]);
                    }
                }
            }
            for(int i=0;i<=n;i++){
                int msk = sn^(1<<i);
                for(int j=0;j<=n;j++)
                    fr[i][rmv] = min(fr[i][rmv],f[j][msk]);
            }
        }
        for(int rmv=0;rmv<=n;rmv++){
            for(int i=0;i<=m;i++)
                for(int j=i+1;j<=m;j++){
                    w[i][j] = 0;
                    for(int l=0;l<=n;l++){
                        if(l == rmv) continue;
                        w[i][j] += abs(a[l][i]-a[l][j]);
                    }
                    w[j][i] = w[i][j];
                }
            for(int i=0;i<=m;i++){
                for(int j=0;j<=sm;j++) f[i][j] = inf;
                f[i][1<<i] = 0;
            }
            for(int s=0;s<=sm;s++){
                for(int i=0;i<=m;i++){
                    if(!((s >> i) & 1)) continue;
                    for(int j=0;j<=m;j++){
                        if((s >> j) & 1) continue;
                        f[j][s|(1<<j)] = min(f[j][s|(1<<j)],f[i][s]+w[i][j]);
                    }
                }
            }
            for(int i=0;i<=m;i++){
                int msk = sm^(1<<i);
                for(int j=0;j<=m;j++)
                    fc[rmv][i] = min(fc[rmv][i],f[j][msk]);
            }
        }
        int ans = inf;
        // for(int i=0;i<=n;i++,puts(""))
        //     for(int j=0;j<=m;j++) cout << fr[i][j] << " ";
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++) ans = min(ans,fc[i][j]+fr[i][j]);
        cout << ans << "\n";
	}
	return 0;
}
