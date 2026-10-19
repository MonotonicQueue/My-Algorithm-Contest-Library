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
const int S = 55;
const int N = 55*12;
int n;
char ch[S],chr[N];
int son[N][26],tot,state[N];
inline void insert(int id){
	int len = strlen(ch+1),p = 0;
	for(int i=1;i<=len;i++){
		int c = ch[i]-'A';
		if(!son[p][c]) son[p][c] = ++tot,chr[tot] = ch[i];
		p = son[p][c];
	}
	state[p] |= 1<<(id-1);
}
int Fail[N];
void getfail(){
	queue<int> q;
	for(int i=0;i<26;i++) if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<26;i++){
			if(son[x][i]){
				Fail[son[x][i]] = son[Fail[x]][i];
				state[son[x][i]] |= state[son[Fail[x]][i]];
				q.push(son[x][i]);
			}else son[x][i] = son[Fail[x]][i];
		}
	}
}
bool vis[N][1<<12];
pii lst[N][1<<12];
pii ed;
void bfs(){
	queue<pii> q;
	q.push(mk(0,0));
	vis[0][0] = true;
	while(!q.empty()){
		int x = q.front().fi,s = q.front().se; q.pop();
		if(s == (1<<n)-1){
			ed = mk(x,s);
			return ;
		}
		for(int i=0;i<26;i++){
			int y = son[x][i],ns = s | state[y];
			if(vis[y][ns]) continue;
			lst[y][ns] = mk(x,s);
			vis[y][ns] = true;
			q.push(mk(y,ns));
		}
	}
}
int top,stk[N*(1<<12)];
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		cin >> ch+1;
		insert(i);
	}
	getfail();
	bfs();
	while(ed != mk(0,0)) stk[++top] = ed.fi,ed = lst[ed.fi][ed.se];
	while(top) cout << chr[stk[top--]];
	return 0;
}