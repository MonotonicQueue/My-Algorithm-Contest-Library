#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int> 
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
int n;
struct node{
	ll val,id;
}b[N][3];
ll a[N][3];
int p[N],cnt[3];
bool cmp1(node x,node y){
	return x.val > y.val;
}
bool cmp(int x,int y){
	return b[x][0].val > b[y][0].val;
}
void solve(){
	n = read();
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++)
			a[i][j] = read();
		ll mn = a[i][0];
		mn = min(mn,a[i][1]);
		mn = min(mn,a[i][2]);
		ans += mn;
		for(int j=0;j<=2;j++)
			a[i][j] -= mn;
		for(int j=0;j<=2;j++){
			b[i][j].id = j;
			b[i][j].val = a[i][j];
		}
		sort(b[i],b[i]+3,cmp1);
		b[i][0].val -= b[i][1].val;
	}
	for(int i=1;i<=n;i++) p[i] = i;
	sort(p+1,p+1+n,cmp);
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=1;i<=n;i++){
		int x = p[i],y = b[x][0].id;
		if(cnt[y] < n/2){
			cnt[y]++;
			ans += b[x][0].val+b[x][1].val;
		}else{
			y = b[x][1].id;
			cnt[y]++;
			ans += b[x][1].val;
		}
	}
	cout << ans << "\n";
} 
int main(){
	int T = read();
	while(T--) solve(); 
	return 0;
}
