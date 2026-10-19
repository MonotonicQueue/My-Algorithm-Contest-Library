#include<bits/stdc++.h>
#define LL __int128
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
const int N = 1e5+10;
int n,m,in[N];
vector<int> G[N];
LL gcd(LL x,LL y){
	return y ? gcd(y,x%y) : x;
}
void output(LL x){
	if(x < 10) putchar('0'+x);
	else output(x/10),putchar('0'+(x%10));
}
struct Frac{
	LL x,y;
	Frac(LL x=0,LL y=1): x(x),y(y) {}
	Frac operator+(const Frac &o)const{
		LL d = gcd(y,o.y),lcm = y/d*o.y;
		LL X = lcm/y*x+lcm/o.y*o.x;
		d = gcd(X,lcm);
		return Frac(X/d,lcm/d);
	}
	Frac operator*(const Frac &o)const{
		LL X = x*o.x,Y = y*o.y;
		LL d = gcd(X,Y);
		return Frac(X/d,Y/d);
	}
	Frac operator/(const LL o)const{
		LL Y = o*y,d = gcd(x,Y);
		return Frac(x/d,Y/d);
	}
	void out(){
		output(x); putchar(' ');
		output(y); putchar('\n');
	}
}f[N];
int main(){
//	freopen("water.in","r",stdin);
//	freopen("water.out","w",stdout);
	n = read(); m = read();
	for(int i=1;i<=n;i++){
		int d = read();
		while(d--){
			int v = read();
			G[i].push_back(v);
			in[v]++;
		}
	}
	for(int i=1;i<=m;i++) f[i] = Frac(1);
	queue<int> q;
	for(int i=1;i<=m;i++) q.push(i);
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(G[x].empty()) continue;
		Frac t = f[x]/G[x].size();
		for(int y : G[x]){
			f[y] = f[y]+t;
			in[y]--;
			if(!in[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(G[i].empty()) f[i].out();
	return 0;
} 