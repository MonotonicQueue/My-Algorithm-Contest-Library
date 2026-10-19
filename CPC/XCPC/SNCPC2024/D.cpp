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
const int M = 25;
const int mod = 998244353;
int n,m1,m2;
char s[N],s1[M],s2[M];
ll f[N][M][M],ans;
void solve(){
	scanf("%s",s+1);  n = strlen(s+1);
	scanf("%s",s1+1); m1 = strlen(s1+1);
	scanf("%s",s2+1); m2 = strlen(s2+1);
	auto add = [&](ll &x,ll y){
		x = x+y >= mod ? x+y-mod : x+y;
	};
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m1;j++){
			for(int k=0;k<=m2;k++){
				f[i][j][k] = f[i-1][j][k];
				if(s1[j] == s[i]){
					add(f[i][j][k],(f[i-1][j-1][k]+(j == 1 && k == 0)*i)%mod);
				}
				if(s2[k] == s[i]){
					add(f[i][j][k],(f[i-1][j][k-1]+(j == 0 && k == 1)*i)%mod);
				}
				if(s1[j] == s[i] && s2[k] == s[i]){
					add(f[i][j][k],(f[i-1][j-1][k-1]+(j == 0 && k == 0)*i)%mod);
				}
			}
		}
		add(ans,f[i][m1][m2]);
	}
	cout << ans << "\n";
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}