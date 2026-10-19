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
const int N = 510;
const int mod = 1e9+7;
int n,K;
char s[N];
bool flag[N][N];
ll f[N][N][5];
// A,AS,SA,AB
signed main(){
    n = read(); K = read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            if(s[j] == '(' || s[j] == ')') break;
            flag[i][j] = true;
        }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = i+len-1;
            if((s[i] == '(' || s[i] == '?') && (s[j] == ')' || s[j] == '?')){
                f[i][j][0] = (f[i+1][j-1][0]+f[i+1][j-1][1]+f[i+1][j-1][2]+f[i+1][j-1][3])%mod;
                //(A) (SA) (AS) (AB)
                if((flag[i+1][j-1] && j-i-1 <= K) || i+1 == j) f[i][j][0]++;
                //(S)
            }
            for(int k=i;k<=j;k++){
                if(k-i+1 > K) break;
                if(s[k] == '(' || s[k] == ')') break;
                f[i][j][2] = (f[i][j][2]+f[k+1][j][0]+f[k+1][j][3])%mod;
            }
            for(int k=j;k>=i;k--){
                if(j-k+1 > K) break;
                if(s[k] == '(' || s[k] == ')') break;
                f[i][j][1] = (f[i][j][1]+f[i][k-1][0]+f[i][k-1][3])%mod;
                f[i][j][4] = (f[i][j][4]+f[i][k-1][0])%mod;
            }
            for(int k=i+1;k<j;k++) f[i][j][3] = (f[i][j][3]+f[i][k][0]*(f[k+1][j][0]+f[k+1][j][3])%mod)%mod;
            for(int k=i+1;k<j;k++) f[i][j][3] = (f[i][j][3]+f[i][k][4]*f[k+1][j][0]%mod)%mod;
            for(int k=i+1;k<j;k++) f[i][j][3] = (f[i][j][3]+f[i][k][4]*f[k+1][j][3]%mod)%mod;
        }
    }
    cout << (f[1][n][0]+f[1][n][3])%mod;
    return 0;
}