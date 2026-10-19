#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
int a[N],len;
ll dp[N][N];
ll dfs(int x,int y,bool st,bool limit){
	if(x > len) return 1;
	if(!limit && dp[x][y] != -1) return dp[x][y];
	ll res = 0; int num = limit ? a[len-x+1] : 9;
	for(int i=0;i<=num;i++){
		if(abs(i-y) < 2) continue;
		if(st && i == 0) res += dfs(x+1,-2,1,limit&&(i==num));
		else res += dfs(x+1,i,0,limit&&(i==num));
	}
	if(!limit && !st) dp[x][y] = res;
	return res;
}
ll work(int x){
	len = 0;
	while(x) a[++len] = x%10,x /= 10;
	memset(dp,-1,sizeof(dp));
	return dfs(1,-2,1,1);
}
int main(){
	int A = read(),B = read();
	cout << work(B)-work(A-1);
	return 0;
}