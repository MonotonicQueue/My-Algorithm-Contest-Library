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
int a[N],cnt;
bool flag[N];
bool chk(int x){
	while(x){
		if(x % 10 > 1) return false;
		x /= 10;  
	}
	return true;
}
void dfs(int x,int id){
	if(x > 1e5 || flag[x]) return ;
	flag[x] = 1;
	for(int i=id;i<=cnt;i++) dfs(x*a[i],id);
}
inline void init(){
	for(int i=1;i<=100000;i++){
		if(chk(i)) a[++cnt] = i; 
	}
	dfs(1,1);
} 
signed main(){
	init();
	int T = read();
	while(T--){
		int n = read();
		puts(flag[n] ? "YES" : "NO");
	}
	return 0;
}//