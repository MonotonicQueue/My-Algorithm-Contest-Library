#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
const int mod = 10007;
int n,m,tot;
char ch[N];
struct Node{
	int son[26];
	int fail,end;
}t[N];
void insert(char ch[]){
	int p = 0,lench = strlen(ch+1);
	for(int i=1;i<=lench;i++){
		int c = ch[i]-'A';
		if(!t[p].son[c]) t[p].son[c] = ++tot;
		p = t[p].son[c];
	}
	t[p].end = 1;
}
void getFail(){
	queue<int>q;
	for(int i=0;i<26;i++)
		if(t[0].son[i]) q.push(t[0].son[i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<26;i++){
			if(t[x].son[i]){
				t[t[x].son[i]].fail = t[t[x].fail].son[i];
				t[x].end |= t[t[x].fail].end;
				q.push(t[x].son[i]);
			}else t[x].son[i] = t[t[x].fail].son[i];
			
		}
	}
}
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1) res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
ll dp[110][N];
ll solve(){
	dp[0][0] = 1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=tot;j++){
			for(int k=0;k<26;k++){
				int y = t[j].son[k];
				if(t[y].end) continue;
				dp[i][y] = (dp[i][y]+dp[i-1][j])%mod;
			}
		}
	ll ans = 0;
	for(int i=0;i<=tot;i++)
		ans = (ans+dp[m][i])%mod;
	return ((fpow(26,m)-ans)%mod+mod)%mod;
}
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		insert(ch);
	}
	getFail(); 
	printf("%lld",solve());
	return 0;
} 