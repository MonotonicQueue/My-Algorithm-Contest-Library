#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 15;
int num[N];
ll dp[N][N][N][2][2][2]; 
//到了第pos位，上一位是x，上两位是y，flag出现3个相同，n4出现4，n8出现8 
ll dfs(int pos,int x,int y,bool flag,bool n4,bool n8,bool fff){
	if(n4 && n8) return 0;
	if(!pos) return flag;
	if(!fff && dp[pos][x][y][flag][n4][n8] != -1) return dp[pos][x][y][flag][n4][n8];
	ll res = 0; int ma = fff ? num[pos] : 9;
	for(int i=0;i<=ma;i++)
		res += dfs(pos-1,i,x,(i==x&&x==y)||flag,n4||(i==4),n8||(i==8),(i==ma)&&fff);
	if(!fff) dp[pos][x][y][flag][n4][n8] = res;
	return res;
}
ll solve(ll x){
	if(x < 1e10) return 0;
	memset(dp,-1,sizeof(dp));
	int len = 0;
	while(x){
		num[++len] = x%10;
		x /= 10;
	}
	ll res = 0;
	for(int i=1;i<=num[len];i++)
		res += dfs(len-1,i,0,0,i==4,i==8,i==num[len]);
	return res;
}
int main() {
	ll a = read(),b = read();
	cout << solve(b)-solve(a-1);
	return 0;
}