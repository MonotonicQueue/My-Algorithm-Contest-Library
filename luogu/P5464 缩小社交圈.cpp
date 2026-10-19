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
const int N = 4100;
const int mod = 1e9+7;
int n,pre[N];
vector<int> v[N];
struct Int{int l,r;}a[N];
ll f[N][N],sum[N][N];
inline void add(ll &x,ll y){
	x = x+y >= mod ? x+y-mod : x+y;
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		int l = read(),r = read();
		a[i] = Int{l,r};
	}
	sort(a+1,a+1+n,[](Int x,Int y){return x.r < y.r;});
	for(int i=1;i<=n;i++){
		pre[i] = 0;
		for(int j=i-1;j;j--)
			if(a[j].r < a[i].l){
				pre[i] = j;
				break;
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i].l > a[j].r){
				sum[i][j] = sum[i][j-1];
				continue;
			}
			add(f[i][j],1);
			if(a[i].l > a[j].l) add(f[i][j],sum[j][pre[i]]);
			else add(f[i][j],sum[i][pre[j]]);
			sum[i][j] = f[i][j];
			add(sum[i][j],sum[i][j-1]);
		}
	}
	ll ans = n;
	for(int i=1;i<=n;i++) add(ans,sum[i][i-1]); 
	cout << ans;
    return 0;
}
