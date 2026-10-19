#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') ch = getchar(),r = -1;
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m;
int T = 1e5+1,F = -T,U = 0;
int fa[N];
bool vis[3*N];
int get(int x){
	if(x == U || x == T || x == F) return x;
	if(vis[x+n]) return T;
	if(vis[n-x]) return U;
	int re = 0;
	if(x > 0){
		if(x == fa[x]) return x;
		vis[x+n] = 1;
		re = fa[x] = get(fa[x]);
		vis[x+n] = 0;
	}else{
		if(x == -fa[-x]) return x;
		vis[x+n] = 1;
		re = get(-fa[-x]);
		vis[x+n] = 0;
	}
	return re;
}
int main(){
	int C = read(),TTT = read();
	while(TTT--){
		n = read(); m = read();
		for(int i=1;i<=n;i++) fa[i] = i;
		for(int i=1;i<=m;i++){
			char ch; scanf("%c",&ch);
			int x = read();
			if(ch == 'T'){
				fa[x] = T;
			}else if(ch == 'F'){
				fa[x] = F;
			}else if(ch == 'U'){
				fa[x] = U;
			}else{
				int y = read();
				if(ch == '+'){
					fa[x] = fa[y];
				}else{
					fa[x] = -fa[y];
				}
			}
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(get(i) == U) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0; 
}
