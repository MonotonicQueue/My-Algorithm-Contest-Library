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
const int N = 1e3+10;
int n,a[N],m;
int id[500];
char s[N][N];
int f[N][5];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=4;j++) f[i][j] = -1e9;
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=4;j++) f[i][j] = f[i-1][j];
        for(int j=0;j<=4;j++){
            int ans = 0,now = j;
                for(int k=1;k<=m;k++){
                    if(!id[int(s[i][k])]) continue;
                    if(id[int(s[i][k])] != now+1){
                        ans--;
                        continue;
                    }
                    now++;
                    if(now == 5) ans += 5,now = 0;
                }
            f[i][now] = max(f[i][now],f[i-1][j]+ans);
        }
    }
    int ans = 0;
    for(int i=0;i<=4;i++) ans = max(ans,f[n][i]-i);
    cout << ans << "\n";
}
int main(){
    id['n'] = 1, id['a'] = 2, id['r'] = 3, id['e'] = 4, id['k'] = 5;
    int T = read();
    while(T--) solve();
    return 0;
}
/*

*/