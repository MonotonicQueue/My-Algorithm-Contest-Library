#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 110;
int n,m;
int a[N][N],b[N][N],c[1145];
int gcd(int x,int y){
	return y ? gcd(y,x%y) : x;
}
bool flag[N][N];
bool chk(int D){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) flag[i][j] = 0;
	flag[1][1] = 1;
	queue<pii> q;
	q.push(mk(1,1));
	while(!q.empty()){
		int x = q.front().fi,y = q.front().se;
		q.pop();
		if(x+1 <= n && !flag[x+1][y] && a[x+1][y]%D == 0){
			flag[x+1][y] = true;
			q.push(mk(x+1,y));
		}
		if(y+1 <= m && !flag[x][y+1] && a[x][y+1]%D == 0){
			flag[x][y+1] = true;
			q.push(mk(x,y+1));
		}
		if(flag[n][m]) return true;
	}
	return false;
}
signed main(){
	int T = read();
	while(T--){
		n = read(); m = read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) a[i][j] = read();
		int d = gcd(a[1][1],a[n][m]);
		int cnt = 0; 
		for(int i=1;i*i<=d;i++)
			if(d % i == 0){
				c[++cnt] = i;
				if(i * i != d) c[++cnt] = d/i;
			}
		sort(c+1,c+1+cnt);
		for(int i=cnt;i;i--){
			if(chk(c[i])){
				printf("%d\n",c[i]);
				break;
			}
		}
	}
	return 0;
}
