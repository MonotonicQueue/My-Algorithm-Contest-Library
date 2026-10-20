#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
int X,Y,A,B;
int get(int x){
	int i = 1;
	for(i=1;i*i<=x;i++);
	return i;
}
void solve(){
	X = read(); Y = read();
	A = read(); B = read();
	if(X == Y){
		puts("YES\n2 2");
		return ;
	}
	bool flag = false;
	if(X < Y) swap(X,Y),swap(A,B),flag = true;
	map<int,pii> mp;
	for(int l=get(X),r=l;l<=min(A,X);l=r+1){
		r = min(X/(X/l),A);
		mp[X/l] = mk(l,r);
	}
	for(int l=get(Y),r=l;l<=min(B,Y);l=r+1){
		r = min(Y/(Y/l),B);
		int t = Y/l;
		if((X-Y) % t != 0) continue;
		if(!mp.count(t)) continue;
		
		auto [L,R] = mp[t];
		int d = (X-Y)/t;
		if(R-d >= l){
			int pos = R-d;
			if(pos <= r){
				puts("YES");
				if(flag) swap(pos,R);
				cout << R << " " << pos << "\n";
				return ;
			}
			pos = r+d;
			if(L <= pos && pos <= R){
				puts("YES");
				if(flag) swap(pos,r);
				cout << pos << " " << r << "\n";
				return ;
			}
		}
	}
	map<vector<int>,int> f;
	vector<int> v;
	for(int i=2;i*i<=X&&i<=A;i++){
		int x = X;
		v.clear();
		while(x){
			v.push_back(x % i);
			x /= i;
		}
		f[v] = i;
	}
	for(int i=2;i*i<=Y&&i<=B;i++){
		int x = Y;
		v.clear();
		while(x){
			v.push_back(x % i);
			x /= i;
		}
		if(f[v]){
			puts("YES");
			if(flag) cout << i << " " << f[v] << "\n";
			else cout << f[v] << " " << i << "\n";
			return ;
		}
	}
	puts("NO");
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
/*

*/