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
const int N = 10100;
const int inf = 1e9;
int n,L[N],R[N];
bitset<N> a[N];
bool flag[N],vis[N];
int dep[N];
int S,T;
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int> q;
	while(!q.empty()) q.pop();
	dep[S] = 1;
	q.push(S);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int y=a[x]._Find_first();y<=T;y=a[x]._Find_next(y)){
			if(dep[y]) continue;
			dep[y] = dep[x]+1;
			if(y == T) return true;
			q.push(y);
		}
	}
	return false;
}
int dinic(int x,int flow){
	if(x == T) return flow;
	int rest = flow;
	for(int y=a[x]._Find_first();y<=T&&rest;y=a[x]._Find_next(y)){
		if(dep[y] != dep[x]+1) continue;
		int k = dinic(y,min(rest,1));
		if(!k) dep[y] = 0;
		else
			a[x][y] = false,
			a[y][x] = true;
		rest -= k;
	}
	return flow-rest;
}
int MF(){
	int ans = 0;
	while(bfs()) ans += dinic(S,inf);
	return ans;
}
int main(){
	n = read();
	S = 2*n+1; T = 2*n+2;
	for(int i=1;i<=n;i++){
		L[i] = read(),R[i] = read();
		a[S][L[i]] = true;
		a[R[i]][T] = true;
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(L[j] < R[i] && R[i] < R[j] && L[i] < L[j])
				a[L[j]][R[i]] = true;
	cout << 2*n-MF();
	return 0;
}