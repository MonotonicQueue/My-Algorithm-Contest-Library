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
const int N = 4e5+10;
int n,X,a[N];
int cnt[30],t[N];
int st[N][20];
inline void st_init(){
	for(int i=1;i<=n;i++) st[i][0] = a[i];
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j] = st[i][j-1]&st[i+(1<<(j-1))][j-1];
}
int ask(int l,int r){
	if(l > r) return (1<<20)-1;
	int k = log(r-l+1)/log(2);
	return st[l][k]&st[r-(1<<k)+1][k];
}
bool flag;
int gcd(int x,int y){
	return y ? gcd(y,x%y) : x;
}
inline void print(int x,int y){
	if(flag) return ; 
	puts("YES");
	cout << "2 ";
	cout << a[x] << " "<< a[y] << "\n";
	cout << n-2 << " ";
	for(int i=1;i<=n;i++) if(i != x && i != y) cout << a[i] << " ";
	cout << "\n";
}
int calc(int x,int y){
	if(x > y) swap(x,y);
	return ask(1,x-1) & ask(x+1,y-1) & ask(y+1,n);
}
void chk1(int x){
	for(int i=1;i<=n;i++){
		if(i == x) continue;
		int y = gcd(a[i],a[x]);
		if(y > calc(i,x)+X){
			print(i,x),flag = true;
			return ;
		}
	}
}
void chk2(int x,int y,int d){
	if(d > calc(x,y)+X) print(y,x),flag = true;
}
bool vis[N];
int main(){
	int T = read();
	while(T--){
		n = read(); X = read();
		for(int i=1;i<=n;i++) a[i] = read(),vis[i] = 0;
		st_init(); flag = false;
		int sum = 0;
		for(int i=0;i<=18&&!flag;i++){
			cnt[i] = 0;
			for(int j=1;j<=n;j++) if((a[j] >> i) % 2 == 0) cnt[i]++;
			if(cnt[i] == 1){
				for(int j=1;j<=n;j++) if((a[j] >> i) % 2 == 0) chk1(j),vis[j] = 1;
			}else if(cnt[i] == 2){
				for(int j=1;j<=n;j++) if((a[j] >> i) % 2 == 0) chk1(j),vis[j] = 1;
			}
			if(cnt[i] == 0) sum += 1<<i;
		}
		if(flag) continue;
//		for(int i=1;i<=n;i++) cout << vis[i] << " ";
//		cout << "\n";
		int maxn = 0;
		for(int i=1;i<=n;i++) if(!vis[i]) ++t[a[i]],maxn = max(maxn,a[i]);
		for(int d=sum+X+1;d<=maxn;d++){
			int ct = 0;
			for(int i=d;i<=maxn;i+=d) ct += t[i];
			if(ct >= 2){
				int aa = 0,bb = 0;
				for(int i=1;i<=n;i++) if(a[i] % d == 0 && !vis[i]){
					if(!aa) aa = i; else bb = i;
				}
				print(aa,bb); flag = true;
				if(flag) break;
			}
		}
		for(int i=1;i<=n;i++) if(!vis[i]) --t[a[i]];
		if(!flag) puts("NO");
	}
	
		
	return 0;
}
