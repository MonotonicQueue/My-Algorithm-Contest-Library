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
const int N = 310;
const int mod = 1e9+7;
int n,Q;
char s[N];
ll f[2][N][N][3],g[N][N][N];
int main(){
    n = read(); Q = read();
    scanf("%s",s+1);
    if(s[1] == '?'){
        f[1][1][0][0] = f[1][0][1][1] = f[1][0][0][2] = 1;
    }else if(s[1] == 'a'){
        f[1][1][0][0] = 1;
    }else if(s[1] == 'b'){
        f[1][0][1][1] = 1;
    }else{
        f[1][0][0][2] = 1;
    }
    for(int i=2;i<=n;i++){
        int c = i & 1;
        memset(f[c],0,sizeof(f[c]));
        if(s[i] == 'a' || s[i] == '?'){
            for(int j=1;j<=n;j++)
                for(int k=0;k+j<=n;k++)
                    f[c][j][k][0] = (f[c][j][k][0]+f[c^1][j-1][k][1]+f[c^1][j-1][k][2])%mod;
        }
        if(s[i] == 'b' || s[i] == '?'){
            for(int j=0;j<=n;j++)
                for(int k=1;k+j<=n;k++)
                    f[c][j][k][1] = (f[c][j][k][1]+f[c^1][j][k-1][0]+f[c^1][j][k-1][2])%mod;
        }
        if(s[i] == 'c' || s[i] == '?'){
            for(int j=0;j<=n;j++)
                for(int k=0;k+j<=n;k++)
                    f[c][j][k][2] = (f[c][j][k][2]+f[c^1][j][k][0]+f[c^1][j][k][1])%mod;
        }
    }
    for(int j=0;j<=n;j++)
        for(int k=0;k+j<=n;k++) g[j][k][n-j-k] = (f[n&1][j][k][0]+f[n&1][j][k][1]+f[n&1][j][k][2])%mod;
    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++)
    for(int k=0;k<=n;k++){
        g[i][j][k] = (g[i][j][k]+g[i-1][j][k])%mod;
    }
    for(int i=0;i<=n;i++) for(int j=1;j<=n;j++)
    for(int k=0;k<=n;k++){
        g[i][j][k] = (g[i][j][k]+g[i][j-1][k])%mod;
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++)
    for(int k=1;k<=n;k++){
        g[i][j][k] = (g[i][j][k]+g[i][j][k-1])%mod;
    }
    int cnta = 0,cntb = 0,cntc = 0;
    for(int i=1;i<=n;i++)
        if(s[i] == 'a') cnta++;
        else if(s[i] == 'b') cntb++;
        else if(s[i] == 'c') cntc++;
    while(Q--){
        int x = read()+cnta,y = read()+cntb,z = read()+cntc;
        cout << g[min(x,n)][min(y,n)][min(z,n)]%mod << "\n";
    }
	return 0;
} 


