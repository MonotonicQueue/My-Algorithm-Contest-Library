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
const int N = 1e4+10;
int n,m;
char s[N],t[N];
int nxt[N],f[N][N];
int main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    n = strlen(s+1); m = strlen(t+1);
    for(int i=1;i<=n;i++){
        if(s[i] == '.') continue;
        int sum = 0;
        for(int j=i;j<=n;j++){
            sum += s[j] == '.' ? -1 : 1;
            if(!sum){
                nxt[i] = j;
                break;
            }
        }
    }
    // for(int i=1;i<=n;i++) cout << nxt[i] << " ";
    // cout << "\n";
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            f[i+1][j] = min(f[i+1][j],f[i][j]+1);
            if(j != m && s[i+1] == t[j+1]) f[i+1][j+1] = min(f[i+1][j+1],f[i][j]);
            if(nxt[i+1]) f[nxt[i+1]][j] = min(f[nxt[i+1]][j],f[i][j]);
        }
    }
    cout << f[n][m];
    return 0;
}