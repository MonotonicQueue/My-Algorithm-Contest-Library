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
const int g = 3,gi = 332748118;
int n,m,a[N];
ll fpow(ll x,ll k){
	ll res = 1;
	while(k){
		if(k & 1)
			res = res*x%mod;
		x = x*x%mod;
		k >>= 1;
	}
	return res;
}
struct poly{
	vector<ll> a;
	ll& operator [](const int x){
		return a[x];
	}
	int len(){return a.size(); }
};
bool operator < (poly x,poly y){
	return x.len() > y.len();
}
vector<ll> NTT(vector<ll> A,int limit,int type,vector<int> rev){
	for(int i=1;i<limit;i++)
		if(i < rev[i]) swap(A[i],A[rev[i]]);
	for(int mid=1;mid<limit;mid<<=1){
		ll gn = fpow(type ? g : gi,(mod - 1)/(mid << 1));
		for(int len=mid<<1,j=0;j<limit;j+=len){
			ll g0 = 1;
			for(int i=0;i<mid;i++){
				ll A0 = A[i+j],A1 = g0*A[i+j+mid]%mod;
				A[i+j] = (A0+A1)%mod;
				A[i+j+mid] = (A0-A1+mod)%mod;
				g0 = g0*gn%mod; 
			}
		}
	}
	if(!type){
		ll inv = fpow(limit,mod-2);
		for(int i=0;i<=limit;i++) A[i] = A[i]*inv%mod;
	}
	return A;
}
poly operator * (poly x,poly y){
	int lenx = x.len()-1,leny = y.len()-1;
	int limit = 1,l = 0;
	while(limit <= (lenx+leny)) limit <<= 1,l++;
	vector<int> rev(limit);
	for(int i=1;i<limit;i++) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	x.a.resize(limit); y.a.resize(limit);
	x.a = NTT(x.a,limit,1,rev);
	y.a = NTT(y.a,limit,1,rev);
	for(int i=0;i<limit;i++) x[i] = x[i]*y[i]%mod;
	x.a = NTT(x.a,limit,0,rev);
	x.a.resize(lenx+leny+1); y.a.clear();
	return x;
}
priority_queue<poly> q;
int main(){
	m = read(); n = read();
	for(int i=1;i<=n;i++){
		a[i] = read();
		vector<ll> v;
		v.resize(a[i]+1);
		v[0] = 1; v[a[i]] = mod-1;
		q.push(poly{v});
	}
	while(q.size() > 1){
		poly x = q.top(); q.pop();
		poly y = q.top(); q.pop();
		x = x*y; q.push(x);
	}
	poly v = q.top();
	ll ans = 0;
	for(int i=0;i<v.len();i++) ans = (ans+(mod-1)*v[i]%mod*m%mod*fpow(i,mod-2)%mod)%mod;
	cout << ans;
    return 0;
}