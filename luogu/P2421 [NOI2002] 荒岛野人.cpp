#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)){
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 20;
const int M = 1e6+10;
int n,m,c[N],p[N],l[N];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){x = 1;y = 0; return a;}
	ll d = exgcd(b,a%b,x,y);
	ll z = x; x = y; y = z-y*(a/b);
	return d;
}
bool chk(int i,int j){
	ll a = ((p[i]-p[j])%m+m)%m,b = m,k = ((c[j]-c[i])%m+m)%m,x,y;
	ll d = exgcd(a,b,x,y);
	if(k % d != 0) return true;
	x = ((x*k/d)%(b/d)+b/d)%(b/d);
	if(x > min(l[i],l[j])) return true;
	return false; 
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		c[i] = read();
		p[i] = read();
		l[i] = read();
		m = max(m,c[i]);
	}
	for(;m<=1e6;m++){
		bool flag = true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!chk(i,j)){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag){
			cout << m;
			return 0;
		}
	}
	return 0;
} 