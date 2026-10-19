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
const int N = 1e5+10;
const int mod = 998244353;
int n,cnt,pos[N];
vector<int> qu[N],G[N];
ll ans[N];
struct node{
	int x; char c;
}t[N];
ll sum(ll l,ll r){
	if(l > r) return 0;
	return (l+r)*(r-l+1)/2%mod;
}
ll s[N],len[N];
int nxt[N],stk[N],top;
void ins(int x,int lst){
	if(!lst){
		nxt[x] = 0;
		s[x] += sum(1,t[x].x-1);
		return ;
	}
	int now = nxt[stk[lst]],mx = 0;
	int y = stk[now+1];
	if(t[x].c == t[y].c){
		mx = t[y].x;
		s[x] += sum(1+len[stk[now]],min(mx,t[x].x)+len[stk[now]]);
		if(t[y].x == t[x].x){
			nxt[x] = now+1;
			return ;
		}
	}
	while(now){
		int i = nxt[stk[now]];
		int d = now-i;
		int y = stk[i+1];
		if(t[y].c == t[x].c){
			s[x] += sum(mx+1+len[stk[i]],min(t[y].x,t[x].x)+len[stk[i]]);
			mx = max(mx,t[y].x);
			if(t[x].x == t[y].x){
				nxt[x] = i+1;
				return ;
			}
		}
		if(i && i > now/2+5 && i%d+d != i){
			i = i%d+d;
			y = stk[i+1];
			if(t[y].c == t[x].c){
				s[x] += sum(mx+1+len[stk[i]],min(t[y].x,t[x].x)+len[stk[i]]);
				mx = max(mx,t[y].x);
				if(t[x].x == t[y].x){
					nxt[x] = i+1;
					return ;
				}
			}
		}
		now = i;
	}
	nxt[x] = 0;
	y = stk[now+1];
	if(t[y].c == t[x].c){
		if(t[x].x-mx > 0) s[x] += len[y]*(t[x].x-mx)%mod,nxt[x] = 1;
	}
}
void dfs(int x,int fa){
	if(x){
		stk[++top] = x;
		len[x] = (len[fa]+t[x].x)%mod;
		ins(x,top-1);
		(s[x] += s[fa]) %= mod;
	}
	for(int id : qu[x]) ans[id] = s[x];
	for(int y : G[x]){
		dfs(y,x);
	}
	top--;
}
int main(){
	n = read();
	int now = 0;
	for(int i=1;i<=n;i++){
		int op = read(),x = read();
		if(op == 1){
			char ch; cin >> ch;
			t[++cnt] = node{x,ch};
			G[now].push_back(cnt);
			now = cnt;
		}else{
			now = pos[x];
		}
		pos[i] = now;
		qu[now].push_back(i);
	}
	dfs(0,0);
	for(int i=1;i<=n;i++) cout << ans[i] << "\n";
	return 0;
}