#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(ch != '-' && !isdigit(ch)) ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e5+10;
int n,k,op,in[N],d[N];
ll a[N],b[N],c[N];
vector<int> G[N];
vector<int> VVV[N];
int ANS;
bool chk(int i,int x){
	for(int j : VVV[i])
		if(a[x]/a[j] == k) return false;
	return true;
}
void dfs(int x,int cnt){
	if(x == n+1){
		ANS = min(ANS,cnt);
		return ;
	}
	for(int i=1;i<=cnt;i++){
		if(chk(i,x)){
			VVV[i].push_back(x);
			dfs(x+1,cnt);
			VVV[i].pop_back();
		}
	}
	VVV[cnt+1].push_back(x);
	dfs(x+1,cnt+1);
	VVV[cnt+1].pop_back();
}
void dfs1(int x,int cnt){
	if(x == n+1){
		if(cnt == ANS){
			cout << cnt << "\n";
			for(int i=1;i<=cnt;i++){
				cout << VVV[i].size() << " ";
				for(int x : VVV[i]) cout << a[x] << " ";
				cout << "\n";
			}
		}
		exit(0);
	}
	for(int i=1;i<=cnt;i++){
		if(chk(i,x)){
			VVV[i].push_back(x);
			dfs1(x+1,cnt);
			VVV[i].pop_back();
		}
	}
	VVV[cnt+1].push_back(x);
	dfs1(x+1,cnt+1);
	VVV[cnt+1].pop_back();
}
void solve(){
	n = read(); k = read(); op = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(op == 0){
		map<ll,int> mp;
		int ans = 1;
		for(int i=1;i<=n;i++){
			c[i] = a[i];
			while(a[i] % k == 0){
				b[i] ^= 1;
				a[i] /= k;
			}
			if(mp.count(a[i]) && mp[a[i]] != b[i]) ans = 2;
			mp[a[i]] = b[i];
		}
		cout << ans << "\n";
		if(ans == 1){
			cout << n << " ";
			for(int i=1;i<=n;i++) cout << c[i] << " ";
		}else{
			vector<ll> v[2];
			for(int i=1;i<=n;i++)
				v[b[i]].push_back(c[i]);
			for(int i=0;i<2;i++){
				cout << v[i].size() << " ";
				for(ll x : v[i]) cout << x << " ";
				cout << "\n";
			}
		}
	}else{ 
		sort(a+1,a+1+n);
		if(n <= 10){
			ANS = n;
			dfs(1,0);
//			cout << ANS << "\n";
			dfs1(1,0);
			return ;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]/a[i] == k) G[i].push_back(j),in[j]++;
			}
		}
		queue<int> q;
		memset(d,-1,sizeof(d));
		for(int i=1;i<=n;i++)
			if(!in[i]) q.push(i),d[i] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int y : G[x]){
				in[y]--;
				if(d[x] != 2){
					if(d[y] == -1) d[y] = d[x]^1;
					else{
						if(d[x] != d[y]) d[y] = 2;
					}
				}
				
				if(!in[y]) q.push(y);
			}
		}
		int ans = 0;
		vector<int> v[3];
		for(int i=1;i<=n;i++) v[d[i]].push_back(i);
		for(int i=0;i<3;i++)
			if(v[i].size()) ans = i;
		cout << ans+1 << "\n";
		for(int i=0;i<=ans;i++){
			cout << v[i].size() << " ";
			for(int x : v[i]) cout << a[x] << " ";
			cout << "\n";
		}
	}
}
int main(){
//	freopen("2.in","r",stdin);
	int T = 1;
	while(T--) solve(); 
	return 0;
}
/*
5 2 0
2 4 8 16 32
	for(int i=1;i<=k;i++) cin >> f[i];
*/