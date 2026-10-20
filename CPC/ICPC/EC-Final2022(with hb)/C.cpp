#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long

using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 22;
int t[N],tot;
__int128 f[N][N][2],pw[N];
//考虑到第i位，当前进位了j次，向下一位有没有进位
void solve(){
	ll x = read(),k = read();
	if(k == 0){
		int cnt = 1;
		while(x){
			if(x % 10 != 9) break;
			x /= 10; cnt++;
		}
		unsigned ll ans = pw[cnt];
		cout << ans << "\n";
		return ;
	}
	memset(t,0,sizeof(t));
	memset(f,0x3f,sizeof(f));
	tot = 0;
	int cnt = 0;
	while(x % 10 == 0) x /= 10,cnt++;
	while(x){
		t[++tot] = x % 10;
		x /= 10;
	}
	f[0][0][0] = 0;
	for(int i=1;i<=20;i++){
		for(int j=0;j<=i;j++){
			f[i][j][0] = min(f[i][j][0],f[i-1][j][0]);
			if(t[i] && j) f[i][j][1] = min(f[i][j][1],f[i-1][j-1][0]+(10-t[i])*pw[i]);
			if(t[i] < 9) f[i][j][0] = min(f[i][j][0],f[i-1][j][1]);
			if(j) f[i][j][1] = min(f[i][j][1],f[i-1][j-1][1]+(10-t[i]-1)*pw[i]);
		}
	}
	if(f[20][k][0] > 1e20) puts("-1");
	else{
		unsigned ll ans = f[20][k][0];
		cout << ans;
		while(cnt--) cout << "0";
		cout << "\n";
	}
}
int main(){
	pw[1] = 1;
	for(int i=2;i<=20;i++) pw[i] = pw[i-1]*10;
	int T = read();
	while(T--) solve();
	return 0;
}