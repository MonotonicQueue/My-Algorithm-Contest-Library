#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int num = 1e5;
struct Question{
	int n,m,a,id;
}Q[N];
int ans[N];
bool cmp(Question x,Question y){
	return x.a < y.a;
}
struct Tree{
	int c[N];
	inline void add(int x,int y){
		while(x <= num){
			c[x] += y;
			x += x&(-x);
		}
	}
	inline int ask(int x){
		int res = 0;
		while(x){
			res += c[x];
			x -= x&(-x);
		}
		return res;
	}
	inline int query(int l,int r){
		return ask(r)-ask(l-1);
	}
}F;
bool vis[N];
int f[N],mu[N],pr[N],tot;
pair<int,int>pi[N];
int work(int x){
	int res = 0;
	for(int i=1;i*i<=x;i++)
		if(x % i == 0){
			if(i*i != x)res += i+x/i;
			else res += i;
		}
	return res;
}
void init(){
	vis[1] = 1; mu[1] = 1; f[1] = 1;
	for(int i=2;i<=num;i++){
		if(!vis[i]){
			vis[i] = 1; pr[++tot] = i;
			mu[i] = -1; f[i] = i+1;
		}
		for(int j=1;j<=tot&&i*pr[j]<=num;j++){
			vis[i*pr[j]] = 1;
			if(i % pr[j] == 0) break;
			mu[i*pr[j]] = -mu[i];
			f[i*pr[j]] = f[i]*f[pr[j]];
		}
	}
	for(int i=1;i<=num;i++)
		if(!f[i]) f[i] = work(i);
	for(int i=1;i<=num;i++) pi[i] = make_pair(f[i],i);
}
int main(){
	int T = read();
	init();
	for(int i=1;i<=T;i++){
		Q[i].n = read(); Q[i].m = read();
		Q[i].a = read(); Q[i].id = i;
	}
	sort(Q+1,Q+1+T,cmp);
	sort(pi+1,pi+1+num);
	for(int i=1,j=1;i<=T;i++){
		while(pi[j].first <= Q[i].a && j <= num){
			for(int k=pi[j].second;k<=num;k+=pi[j].second)
				F.add(k,pi[j].first*mu[k/pi[j].second]);
			j++;
		}
		int n = Q[i].n,m = Q[i].m,id = Q[i].id;
		if(n > m) swap(n,m);
		for(int l=1,r;l<=n;l=r+1){
			r = min(n/(n/l),m/(m/l));
			ans[id] += F.query(l,r)*(n/l)*(m/l);
		}
	}
	ll mod = (1ll<<31);
	for(int i=1;i<=T;i++) printf("%lld\n",(ll)(ans[i]%mod+mod)%mod);
	return 0;
} 