#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
const int mod = 998244353;
int n,a[N],m = (1<<30)-1;
int t[N*40];
void add(int &x,int y){
	x = x+y >= mod ? x+y-mod : x+y;
}
int lst[N][32];
struct node{
	int op,now,id;
};
vector<node> q[N];
vector<pair<int,int>> vc[N];
int b[N*40],tot;
void addc(int x,int y){
	while(x <= tot){
		add(t[x],y);
		x += x&(-x);
	}
}
int ask(int x){
	int res = 0;
	while(x){
		add(res,t[x]);
		x -= x&(-x);
	}
	return res;
}
double st = clock();
void solve(){
	// freopen("D.in","r",stdin);
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<=29;j++)
			lst[i][j] = lst[i-1][j];
		for(int j=0;j<=29;j++)
			if((a[i] >> j) & 1) lst[i][j] = i;
	}
	for(int i=1,sum=0;i<=n;i++){
		int now = a[i],k = i;
		sum |= a[i];
		vector<tuple<int,int,int>> v;
		while(true){
			int mx = 0;
			for(int j=0;j<30;j++){
				if((now >> j) & 1) continue;
				mx = max(mx,lst[k-1][j]);
			}
			v.emplace_back(mx+1,k,now);
			if(mx == 0) break;
			now |= a[mx]; k = mx;
		}
		b[++tot] = sum;
		for(auto &[l,r,x] : v){
			b[++tot] = x;
			q[l-1].push_back(node{mod-1,x,i});
			q[r].push_back(node{1,x,i});
		}
	}
	sort(b+1,b+1+tot);
	tot = unique(b+1,b+1+tot)-b-1;
	int ans = 0;
	for(int i=1,sum=0;i<=n;i++){
		sum |= a[i];
		for(auto &[op,x,id] : q[i]){
			int y = lower_bound(b+1,b+1+tot,x)-b;
			vc[id].emplace_back(y,1ll*op*ask(y)%mod);
		}
		if(i == n){
			ans++;
			for(auto [x,c] : vc[i]) add(ans,c);
		}else{
			int y = lower_bound(b+1,b+1+tot,sum)-b;
			addc(y,1);
			for(auto &[x,c] : vc[i]){
				addc(x,c);
			}
		}
	}
	cout << ans << "\n";
	// cerr << (clock()-st)/CLOCKS_PER_SEC;
}
int main(){
	int T = 1;
	while(T--) solve();
    return 0;
}