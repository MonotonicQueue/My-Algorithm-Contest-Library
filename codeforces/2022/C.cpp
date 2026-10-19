#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e5+10;
const int inf = 1e9;
int n,f[N][3];
char s[2][N];
void solve(){
    n = read();
    scanf("%s",s[0]+1);
    scanf("%s",s[1]+1);
    for(int i=0;i<=n;i++) f[i][0] = f[i][1] = f[i][2] = -inf;
    f[0][0] = 0;
    //前i列铺满了第i+1列的状态0/1/2
    auto chkmx = [&](int &x,int y){
        x = max(x,y);
    };
    for(int i=0;i<n;i++){
        int cnt = 
        ((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[0][i+3]=='A') >= 2)+
        ((s[1][i+1]=='A')+(s[1][i+2]=='A')+(s[1][i+3]=='A') >= 2);
        chkmx(f[i+3][0],f[i][0]+cnt);
        cnt = 
        ((s[0][i+2]=='A')+(s[0][i+3]=='A')+(s[0][i+4]=='A') >= 2)+
        ((s[1][i+1]=='A')+(s[1][i+2]=='A')+(s[1][i+3]=='A') >= 2);
        chkmx(f[i+3][1],f[i][1]+cnt);
        cnt = 
        ((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[0][i+3]=='A') >= 2)+
        ((s[1][i+2]=='A')+(s[1][i+3]=='A')+(s[1][i+4]=='A') >= 2);
        chkmx(f[i+3][2],f[i][2]+cnt);
        chkmx(f[i+1][1],f[i][0]+((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[1][i+1]=='A') >= 2));
        chkmx(f[i+1][2],f[i][0]+((s[0][i+1]=='A')+(s[1][i+2]=='A')+(s[1][i+1]=='A') >= 2));
        chkmx(f[i+2][0],f[i][1]+((s[1][i+1]=='A')+(s[0][i+2]=='A')+(s[1][i+2]=='A') >= 2));
        chkmx(f[i+2][0],f[i][2]+((s[0][i+1]=='A')+(s[0][i+2]=='A')+(s[1][i+2]=='A') >= 2));
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=2;j++)
    //         if(f[i][j] >= 0) cout << f[i][j] << " ";
    //         else cout << "-inf ";
    //     cout << "\n";
    // }
    cout << f[n][0] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}