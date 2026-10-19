#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int inf = 2e9;
int ask(int k);
int cheat(); 
vector<ll> ans,A,B;
vector<pair<ll,ll> > v;
bool chk(int n,int q){
	v.clear();
	for(int i=0;i<q;i++) v.push_back(mk(A[i]%n,B[i]));
	sort(v.begin(),v.end());
	for(int i=0;i<q;i++)
		if(v[i].fi == v[(i+1)%q].fi && v[i].se != v[(i+1)%q].se) return false;
	if(q > 2)
		for(int i=0;i<q;i++)
			if(v[i].se == v[(i+1)%q].se && v[i].se == v[(i+2)%q].se) return false;
	v.erase(unique(v.begin(),v.end()),v.end()); q = v.size();
	ll mn = 0,mx = 0;
	for(int i=1;i<q;i++){
		if(v[i].se < v[mn].se) mn = i;
		if(v[i].se > v[mx].se) mx = i;
	}
	for(int i=mn,lst=-inf;i!=mx;i=(i+1)%q){
		if(v[i].se < lst) return false;
		lst = v[i].se;
	}
	for(int i=mx,lst=inf;i!=mn;i=(i+1)%q){
		if(v[i].se > lst) return false;
		lst = v[i].se;
	}
	return true;
}
int buer(int T) {
	mt19937 rnd(time(0));
	for(int i=2;i<=1000000;i++) ans.push_back(i);
	ll d = 0;
	for(int q=1;ans.size()>1;q++){
		ll k = rnd()%100000000+1; d += k;
		A.push_back(d);
		B.push_back(ask(k));
		if(q > 5){
			vector<ll> C;
			for(ll i:ans) if(chk(i,q)) C.push_back(i);
			ans = C;
		}
	}
	int n = ans[0];
	int mx = 0,siz = A.size();
	for(int i=1;i<siz;i++) if(B[mx] < B[i]) mx = i;
	int p = ask(n-(d-A[mx])%n),q = ask(1);
	if(p < q){
		int v = q;
		for(int k=20;~k;k--){
			p = ask(1<<k); q = ask(1);
			if(v < p  && p < q) v = q;
			else ask(n-((1<<k)%n)-1+n);
		}
		return max(v,ask(1));
	}else{
		int v = q;
		for(int k=20;~k;k--){
			p = ask(n-(1<<k)%n); q = ask(n-1);
			if(v < p && p < q) v = q;
			else ask((1<<k)+1);
		}
		return max(v,ask(n-1));
	}
	return 0;
}
