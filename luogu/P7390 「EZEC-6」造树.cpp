#include <bits/stdc++.h>
#define pii pair<long long,int> 
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N  = 1e7+10;
int n,m=500000;
unsigned seed;
unsigned rnd() {seed ^= seed << 13, seed ^= seed >> 17, seed ^= seed << 5; return seed;}
int rand(int l, int r) {return rnd() % (r - l + 1) + l;}
struct node{
	ll a,b;
}a[N];
bool cmp(node x,node y){
	return x.b < y.b;
}
void init_data(){
	cin>>seed;
	for(int i = 1; i <= n; ++i) a[i].a = 1, a[i].b = rand(1, m);
	for(int i = 1; i <= n - 2; ++i) ++a[rand(1, n)].a;
}
queue<ll> q,p;
int main(){
	int type;
	cin >> type >> n;
	if(type == 1) init_data();
	else{
		for(int i=1;i<=n;i++) cin >> a[i].a;
		for(int i=1;i<=n;i++) cin >> a[i].b;
	}
	sort(a+1,a+1+n,cmp);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		if(!p.empty()) ans += p.front()*a[i].b,a[i].a--,p.pop();
		while(a[i].a--) p.push(a[i].b);
		while(p.size() > 1 && !q.empty()) ans += p.front()*q.front(),q.pop(),p.pop();
		if(p.size() == 1) q.push(p.front()),p.pop();
	}
	ll val = q.front(); q.pop();
	cout << ans+val*q.front();
//	cout << "\n" << p.size();
	return 0; 
}
