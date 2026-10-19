#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
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
const int N = 1e6+10;
const int M = 1e6+10;
int n,m,L,V,p[N]; 
struct Car{
	double d,v,a;
}c[N];
bool cmp(Car x,Car y){
	return x.d < y.d;
}
int s[M][2],sum[M];
int flag[M];
vector<int> g[M];
inline void clear(){
	for(int i=0;i<=L+1;i++) s[i][0] = s[i][1] = sum[i] = 0,g[i].clear(),flag[i] = 0;
}
ll get(ll v,ll V,ll aa,ll d,bool op){
	if(aa < 0) aa = -aa,swap(v,V);
	ll s = 1.0*(V*V-v*v)/aa/2.0;
	if(op == 0) while(V*V-v*v >= 2*aa*s) s++;
	else while(V*V-v*v > 2*aa*s) s++;
	return s+d;
}
void solve(){
	n = read(); m = read();
	L = read(); V = read();
	clear();
	for(int i=1;i<=n;i++){
		c[i].d = read();
		c[i].v = read();
		c[i].a = read();
	}
	for(int i=1;i<=m;i++) p[i] = read(),sum[p[i]]++,flag[p[i]] = i;
	for(int i=1;i<=L;i++) sum[i] += sum[i-1];
	int ans1 = 0,ans2 = 0;
	for(int i=1;i<=n;i++){
		ll st = 0,ed = 0;
		if(c[i].a == 0){
			if(c[i].v > V){
				st = c[i].d; ed = L+1;
				s[st][0]++; 
			}else continue;
		}else if(c[i].a > 0){
			if(c[i].v > V){
				st = c[i].d; ed = L+1;
				s[st][0]++; 
			}else{
				st = get(c[i].v,V,c[i].a,c[i].d,0);
				ed = L+1;
				if(st <= L) s[st][0]++;	
				else continue;
			}
		}else{
			if(c[i].v <= V) continue;
			st = c[i].d; s[st][0]++; 
			ed = get(c[i].v,V,c[i].a,c[i].d,1);
			if(ed <= L) s[ed][1]++;
			else ed = L+1;
		}
		if(sum[ed-1]-(st > 0 ? sum[st-1] : 0) > 0) ans1++;
		g[st].push_back(ed);
	} 
	for(int i=1;i<=L;i++) s[i][1] += s[i-1][1];
	priority_queue<int> q;
	for(int i=0;i<=L;i++){
		for(int x : g[i]) q.push(-x);
		while(!q.empty() && -q.top() <= i) q.pop();
		if(flag[i]){
			if(q.empty()) ans2++;
			else if(flag[i] != m){
				if(-q.top() > p[flag[i]+1]) ans2++;
				else{
					while(!q.empty()) q.pop();
				}	
			} 
			
		}
	}
	cout << ans1 << " " << ans2 << "\n"; 
}
int main(){
// 	freopen("detect.in","r",stdin);
// 	freopen("detect.out","w",stdout);
	int T = read();
	while(T--) solve();
	return 0;
}