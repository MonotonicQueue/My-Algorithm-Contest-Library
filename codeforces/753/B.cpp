#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e4+10;
struct node{
	int x[5],val;
	int A(node y){
		int res = 0;
		for(int i=0;i<4;i++)
			res += x[i] == y.x[i];
		return res;
	}
	int B(node y){
		int res = 0;
		vector<int> t(10,0);
		for(int i=0;i<4;i++) t[y.x[i]]++;
		for(int i=0;i<4;i++) res += t[x[i]];
		return res-A(y);
	}
}a[N],b[N];
int cnt,now[5]; bool vis[15];
void dfs(int x){
	if(x >= 4){
		++cnt;
		for(int i=0;i<4;i++) a[cnt].x[i] = now[i];
		return ;
	}
	for(int i=0;i<=9;i++){
		if(vis[i]) continue;
		now[x] = i;
		vis[i] = true;
		dfs(x+1);
		vis[i] = false;
	}
}
int turn,ttt[5][5];
bool solve(){
	if(turn){
		for(int i=1;i<=cnt;i++){
			a[i].val = 0;
			for(int k=0;k<=4;k++)
				for(int j=0;j+k<=4;j++) ttt[k][j] = 0;
			for(int j=1;j<=cnt;j++)
				ttt[a[i].A(a[j])][a[i].B(a[j])]++;
			for(int k=0;k<=4;k++)
				for(int j=0;j+k<=4;j++) a[i].val = max(a[i].val,ttt[k][j]);
		}
		auto cmp = [=](node x,node y){
			if(x.val != y.val) return x.val < y.val;
			for(int i=0;i<4;i++) if(x.x[i] != y.x[i]) return x.x[i] < y.x[i];
			return false;
		};
		sort(a+1,a+1+cnt,cmp);
	}
	// cout << cnt << "\n";
	turn++;
	for(int i=0;i<4;i++) cout << a[1].x[i];
	cout << "\n";
	fflush(stdout);
	int A = read(),B = read();
	if(A == 4) return true;
	node x = a[1];
	int tot = 0;
	for(int i=1;i<=cnt;i++){
		if(x.A(a[i]) != A || x.B(a[i]) != B) continue;
		b[++tot] = a[i]; 
	}
	cnt = tot;
	for(int i=1;i<=cnt;i++) a[i] = b[i];
	return false;
}
int main(){
	dfs(0);
	while(!solve());
	return 0;
}