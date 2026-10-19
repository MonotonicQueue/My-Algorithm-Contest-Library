#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 5e5+10;
ll n,a[N],s[N];
ll stk[N],top,l[N],r[N],sl[N],sr[N],ans[N];
vector<int> vl[N],vr[N];
int t[N];
inline void clear(){
	for(int i=1;i<=n;i++) t[i] = 0;
}
inline void add(int x,int y){
	while(x <= n){
		t[x] = max(t[x],y);
		x += x&(-x);
	}
}
int ask(int x){
	int res = 0;
	while(x){
		res = max(res,t[x]);
		x -= x&(-x);
	}
	return res;
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++){
			while(top && a[i] < a[stk[top]]){
				r[stk[top]] = i;
				top--;
			}
			l[i] = stk[top];
			stk[++top] = i;
		}
		while(top) r[stk[top--]] = n+1;
		
		for(int i=0;i<=n+1;i++) vl[i].clear(),vr[i].clear(),sl[i] = sr[i] = s[i] = 0;
		for(int i=1;i<=n;i++){
			vl[l[i]].push_back(i);
			vr[r[i]].push_back(i);
			s[l[i]+1] += a[i];
			s[r[i]] -= a[i];
		}
		for(int i=1;i<=n;i++) s[i] += s[i-1];
		clear();
		for(int i=1;i<=n;i++){
			for(int x : vl[i])
				sl[x] = ask(a[x]);
			add(a[i],i);
		}
		clear();
		for(int i=n;i;i--){
			for(int x : vr[i])
				sr[x] = n-ask(a[x])+1;
			add(a[i],n-i+1);
		}
		for(int i=0;i<=n+1;i++) ans[i] = 0;
		for(int i=1;i<=n;i++){
			ll len0 = i-l[i],len1 = r[i]-i;
			ans[1] += len0*len1*a[i];
			ans[l[i]+1] -= len0*len1*a[i];
			ans[l[i]+1] += (len0-1)*len1*a[i];
			ans[i] -= (len0-1)*len1*a[i];
			ans[i+1] += len0*(len1-1)*a[i];
			ans[r[i]] -= len0*(len1-1)*a[i];
			ans[r[i]] += len0*len1*a[i];
		}
		for(int i=1;i<=n;i++) ans[i] += ans[i-1];
		for(int i=1;i<=n;i++){
			if(l[i] >= 0){
				ll len0 = l[i]-sl[i]-1,len1 = r[i]-i;
				ans[l[i]] += len0*len1*a[i];
			}
			if(r[i] <= n){
				ll len0 = i-l[i],len1 = sr[i]-r[i]-1;
				ans[r[i]] += len0*len1*a[i];
			}
		}
		for(int i=1;i<=n;i++) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}