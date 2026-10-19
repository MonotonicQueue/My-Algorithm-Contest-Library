#include<bits/stdc++.h>
#define ll long long 
#define int64 __int128
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
void read(__int128 &x){
	// read a __int128 variable
	char c; bool f = 0;
	while(((c = getchar()) < '0' || c > '9') && c != '-');
	if(c == '-'){f = 1; c = getchar();}
	x = c - '0';
	while((c = getchar()) >= '0' && c <= '9')x = x * 10 + c - '0';
	if(f) x = -x;
}
void write(__int128 x){
	// print a __int128 variable
	if(x < 0){putchar('-'); x = -x;}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 1e5+10;
const int K = 125;
int c,T;
int n,m,k;
int son[N*K][2],tot;
ll sum[N*K],b[N];
int64 mn[N*K],a[N],MX;
inline void insert(int x){
	int p = 1;
	sum[1] += b[x];
	mn[1] = min(mn[1],a[x]);
	for(int i=k-1;~i;i--){
		bool c = (a[x]>>i)&1;
		if(!son[p][c]){
			son[p][c] = ++tot;
			mn[tot] = MX;
			sum[tot] = 0;
			son[tot][0] = son[tot][1] = 0;
		}
		p = son[p][c];
		sum[p] += b[x]; mn[p] = min(mn[p],a[x]);
	}
}
void clear(){
	for(int i=1;i<=tot;i++)	son[i][0] = son[i][1] = mn[i] = sum[i] = 0;
	tot = 1;
}
int64 ans;
#define ls son[p][0]
#define rs son[p][1]
void solve(int p,int d,ll s,int64 x,int64 y,int64 z){
	if(d == -1){
		ans = max(ans,z);
		return ;
	}
	int64 bit = (int64)1<<d,mask = bit-1;
	if(!p){
		ans = max(ans,(x|bit|mask)+y);
		return ;
	}
	bool flag = false;
	
	if(sum[ls] <= s && (x|mask)+min(y,mn[ls]) >= (z|bit))
		solve(rs,d-1,s-sum[ls],x,min(y,mn[ls]),z|bit),flag = true;
	
	if(sum[rs] <= s && (x|bit|mask)+min(y,mn[rs]) >= (z|bit))
		solve(ls,d-1,s-sum[rs],x|bit,min(y,mn[rs]),z|bit),flag = true;
	
	if(flag) return ;
	solve(ls,d-1,s,x,y,z);
	solve(rs,d-1,s,x|bit,y,z);
	
}
signed main(){
// 	freopen("xor.in","r",stdin);
// 	freopen("xor.out","w",stdout); 
	c = read(); T = read();
	while(T--){
		clear(); ans = 0;
		n = read(); m = read(); k = read();
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) b[i] = read();
		sum[1] = 0; MX = mn[1] = mn[0] = (int64)1<<k;
		for(int i=1;i<=n;i++) insert(i);
		if(sum[1] <= m){
			write(MX-1+mn[1]);
			puts("");
			continue;
		}
		solve(1,k-1,m,0,MX,0);
		write(ans); puts("");
	}
	return 0; 
}
