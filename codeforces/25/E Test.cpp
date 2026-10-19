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
const int N = 4;
const int M = 3e5+10;
const int S = 10;
int n;
int p[N][N],nxt[M];
int f[N][S];
bool vis[N][N];
string s[N];
inline void work(int x,int y){
	int lenx = s[x].size()-1,leny = s[y].size()-1,i,j;
	for(i=1,j=0;i<=lenx;i++){
		while(j && s[x][i] != s[y][j+1]) j = nxt[j];
		if(s[x][i] == s[y][j+1]) j++;
		if(j == leny){
			j = nxt[j];
			vis[x][y] = true;
		}
	}
	p[x][y] = leny-j;
}
inline void get_kmp(int x){
	int len = s[x].size()-1;
	for(int i=2,j=0;i<=len;i++){
		while(j && s[x][i] != s[x][j+1]) j = nxt[j];
		if(s[x][i] == s[x][j+1]) j++;
		nxt[i] = j;
	}
	for(int i=1;i<=n;i++) if(i != x) work(i,x);
}
int main(){
	n = 3;
	for(int i=1;i<=n;i++) cin >> s[i];
	for(int i=1;i<=n;i++) s[i] = " "+s[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) get_kmp(i);
	for(int i=1;i<=n;i++) f[i][1<<(i-1)] = s[i].size()-1;
	for(int s=0;s<(1<<n);s++){
		for(int i=1;i<=n;i++){
			if(s & (1<<(i-1)) == 0) continue;
			for(int j=1;j<=n;j++){
				if(i == j) continue;
				f[j][s|(1<<(j-1))] = min(f[j][s|(1<<(j-1))],f[i][s]+p[i][j]);
				if(vis[i][j]) f[i][s|(1<<(j-1))] = min(f[i][s|(1<<(j-1))],f[i][s]);
			}
		}
	}
	int ans = 1e9;
	for(int i=1;i<=n;i++) ans = min(ans,f[i][(1<<n)-1]);
	cout << ans;
	return 0;
}