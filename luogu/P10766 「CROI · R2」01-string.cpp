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
const int N = 5e5+10;
int n,dp[N][3];
char s[N],t[N];
int main(){
    int T = read();
    while(T--){
        scanf("%s",s+1); scanf("%s",t+1);
        n = strlen(s+1); 
        memset(dp,0x3f,sizeof(dp));
        dp[1][0] = 1+(t[1] == '1');
        dp[1][1] = 1+(t[1] == '0');
        dp[1][2] = (t[1] != s[1]);
        for(int i=2;i<=n;i++){
            if(t[i] == '0'){
                for(int j=0;j<=2;j++)
                    dp[i][0] = min(dp[i][0],dp[i-1][j]+(j!=0));
                dp[i][1] = min(dp[i-1][1]+(t[i-1]=='1'),min(dp[i-1][0]+(t[i-1]=='0'),dp[i-1][2]+(t[i-1]==s[i-1]))+1);
            }else{
                dp[i][0] = min(dp[i-1][0]+(t[i-1]=='0'),min(dp[i-1][1]+(t[i-1]=='1'),dp[i-1][2]+(t[i-1]==s[i-1]))+1);
                for(int j=0;j<=2;j++)
                    dp[i][1] = min(dp[i][1],dp[i-1][j]+(j!=1));
            }
            if(s[i] == t[i]) for(int j=0;j<=2;j++) dp[i][2] = min(dp[i][2],dp[i-1][j]);
            else dp[i][2] = min(dp[i-1][0]+(t[i-1]=='0'),min(dp[i-1][1]+(t[i-1]=='1'),dp[i-1][2]+(t[i-1]==s[i-1])));
        }
        int ans = 1e9;
        for(int i=0;i<=2;i++) ans = min(ans,dp[n][i]);
        cout << ans << "\n";
    }
	return 0;
}
