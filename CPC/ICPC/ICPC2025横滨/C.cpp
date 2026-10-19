#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
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
const int N = 4e5+10;
int n,a[N],b[N],pos[N];
multiset<pair<pii,int>> ans;
// void work(int l,int r){
// 	int mn = 1e9;
// 	for(int i=l;i<=r;i++) mn = min(mn,a[i]);
// 	for(int i=l;i<=r;i++) a[i] -= mn;
// 	if(mn) ans.insert(mk(mk(l,r),mn));
// 	int lst = 0;
// 	for(int i=l;i<=r;i++){
// 		if(!lst && a[i]) lst = i;
// 		if(lst && !a[i]) work(lst,i-1),lst = 0;
// 	}
// 	if(lst) work(lst,r);
// }
int stk[N],top;
void solve(){
	n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int mn = 1e9;
	for(int i=1;i<=n;i++) mn = min(mn,a[i]);
	for(int i=1;i<=n;i++) a[i] -= mn;
	int fi = 0;
	for(int i=1;i<=n;i++)
		if(!a[i]){
			fi = i;
			break;
		}else a[i+n] = a[i];
	// work(fi,fi+n-1);
	
	for(int i=fi;i<=fi+n;i++){
		int lst = top;
		while(top && a[stk[top]] > a[i]){
			ans.insert(mk(mk(stk[top],i-1),a[stk[top]]-max(a[i],a[stk[top-1]])));
			pos[stk[top]] = i-1;
			top--;
		}
		if(a[i] > a[stk[top]]){
			if(lst != top) top++,a[stk[top]] = a[i];
			else stk[++top] = i;
		}
	}
	// int sum = 0;
	// for(int i=fi;i<=fi+n;i++){
	// 	sum += b[i];
	// 	a[i] += sum;
		
	// 	if(pos[i]){
	// 		ans.insert(mk(mk(i,pos[i]),a[i]));
	// 		sum -= a[i];
	// 		b[pos[i]+1] += a[i];
	// 	}
		
	// }
	pii lst = mk(0,0);
	while(mn){
		bool flag = true;
		for(auto it=ans.lower_bound(mk(lst,0));it!=ans.end();it++){
			lst = it->fi;
			auto nxt = ans.upper_bound(mk(mk(it->fi.se+1,0),0));
			while(nxt != ans.end()){
				if(nxt->fi.se > n && nxt->fi.se >= it->fi.fi+n) nxt++;
				else break;
			}
			// cout << "114514";
			if(nxt == ans.end()) continue;
			// if(nxt->fi == it->se+1){
			// 	pii x = mk(it->fi,nxt->se);
			// 	ans.erase(it); ans.erase(nxt);
			// 	ans.insert(x);
			// 	flag = false;
			// 	break;
			// }
			// cout << it->fi.fi << " " << it->fi.se << " " << nxt->fi.fi << " " << nxt->fi.se << "\n";

			pii x = mk(it->fi.fi,nxt->fi.se),y = mk(nxt->fi.fi,it->fi.se+n);
			x.fi = (x.fi-1)%n+1; y.fi = (y.fi-1)%n+1;
			x.se = (x.se-1)%n+1; y.se = (y.se-1)%n+1;
			if(x.fi > x.se) x.se += n;
			if(y.fi > y.se) y.se += n;
			if(x.se < fi) x.se += n,x.fi += n;
			if(y.se < fi) y.se += n,y.fi += n;
			pair<pii,int> a = mk(it->fi,it->se-1),b = mk(nxt->fi,nxt->se-1);
			
			ans.erase(it); ans.erase(nxt);
			if(a.se) ans.insert(a);
			if(b.se) ans.insert(b);
			ans.insert(mk(x,1)); ans.insert(mk(y,1));
			flag = false;
			mn--; break;
		}
		if(flag) break;
	}
	ans.insert(mk(mk(1,n),mn));
	ll ccc = 0;
	for(auto it : ans) ccc += it.se;
	cout << ccc << "\n";
	if(ccc <= 200000)
		for(auto it : ans){
			for(int i=1;i<=it.se;i++)
				cout << (it.fi.fi-1)%n+1 << " " << (it.fi.se-1)%n+1 << "\n";
		}
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
6
 1 2 1 2 2 1
*/