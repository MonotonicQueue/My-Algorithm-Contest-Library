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
const int N = 110;
int n,m,T,cnt,now;
int t[N],a[N],ans[N],pos[N],fir[N];
bool flag[N][N];
queue<int> q[N];
/*
(i+cnt-1)
*/
priority_queue<pii,vector<pii>,greater<pii> >Q;
inline int s(int i){
	//CPU 对应的队列 
	return (i+cnt-1)%m+1;
}
void out(int x){
	if(a[pos[x]] <= 0) ans[pos[x]] = now;
	else q[s(x)].push(pos[x]);
	pos[x] = 0;
}
void in(int x){
//	assert(cnt == now/T); 
	if(q[s(x)].empty()){
		return ;
	}
	int y = t[x]; pos[x] = q[s(x)].front(); q[s(x)].pop();
	if(fir[pos[x]] == -1) fir[pos[x]] = now;
	if(flag[x][pos[x]]) y = min(y,(a[pos[x]]+1)/2);
	else y = min(y,a[pos[x]]);
	a[pos[x]] -= y*(flag[x][pos[x]]+1);
	a[pos[x]] = max(a[pos[x]],0);
	Q.push(mk(now+y,x));
}
void solve(){
	memset(fir,-1,sizeof(fir));
	n = read(); m = read(); T = read();
	for(int i=1;i<=m;i++) t[i] = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		int k = read();
		while(k--){
			int x = read();
			flag[x][i] = true;
		}
	}
	for(int i=1;i<=n;i++)
		q[(i-1)%m+1].push(i);
	
	for(int i=1;i<=m;i++) Q.push(mk(0,i));
	while(!Q.empty()){
		int x = Q.top().se,ti = Q.top().fi;
		if(cnt+1 < ti/T || (cnt < ti/T && ti % T != 0)){
			cnt++;
			now = cnt*T;
			for(int i=1;i<=m;i++)
				if(!pos[i]) in(i);
			continue;
		}
		Q.pop();
		vector<int> v; v.push_back(x);
		while(!Q.empty() && Q.top().fi == ti){
			v.push_back(Q.top().se);
			Q.pop();
		}
//		cout << ti << ": ";
//		for(int x : v) cout << x << " ";
//		cout << "\n";
		if(cnt != ti/T){
//			assert(cnt == ti/T-1);
//			while(cnt+1 < ti/T){
//				cnt++; now = cnt*T;
//				for(int i=1;i<=m;i++)
//					if(!pos[i]) in(i);
//			}
			now = ti;
			if(ti%T == 0){
				cnt = now/T-1;
				for(int x : v) out(x);
				cnt = now/T;
				for(int i=1;i<=m;i++)
					if(!pos[i]) in(i);
//				for(int x : v) in(x);
			}else{
//				now = (now/T)*T;
//				for(int i=1;i<=m;i++)
//					if(!pos[i]) in(i);
				cnt = now/T;
				for(int x : v) out(x);
				for(int i=1;i<=m;i++)
					if(!pos[i]) in(i);
//				for(int x : v) in(x);
			}
		}else{
			now = ti;
			for(int x : v) out(x);
			for(int i=1;i<=m;i++)
				if(!pos[i]) in(i);
		}
				for(int i=1;i<=m;i++)
					if(!pos[i]) in(i);
		assert(cnt == now/T);
	}
	for(int i=1;i<=n;i++) cout << ans[i]-fir[i] << " ";
}
int main(){
	int T = 1;
	while(T--) solve(); 
	return 0;
}