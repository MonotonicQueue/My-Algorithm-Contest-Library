#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 6e5+10;
const int K = 27;
int n,q,a[N],m;
int b[K][N];
struct BIT{
	ll t[N];
	inline void add(int x,int y){
		while(x <= m){
			t[x] += y;
			x += x&(-x);
		}
	}
	inline ll ask(int x){
		ll res = 0;
		while(x){
			res += t[x];
			x -= x&(-x);
		} 
		return res;
	}
}T[K];
map<int,int> mp;
int tot;
bool chk(int l,int r,int x){
	for(int k=1;k<=25;k++){
		ll res = T[k].ask(r)-T[k].ask(l-1);
		if(res % x) return false;
	}
	return true;
}
int main(){
	srand(time(0));
	n = read(); q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	m = n+q;
	for(int k=1;k<=25;k++){
		for(int i=1;i<=m;i++) b[k][i] = i;
		random_shuffle(b[k]+1,b[k]+1+m);
	}
	for(int i=1;i<=n;i++){
		if(!mp[a[i]]) mp[a[i]] = ++tot;
		a[i] = mp[a[i]];
	}
	for(int i=1;i<=n;i++)
		for(int k=1;k<=25;k++)
			T[k].add(i,b[k][a[i]]);
	while(q--){
		int op = read();
		if(op == 1){
			int i = read(),x = read();
			if(!mp[x]) mp[x] = ++tot;
			x = mp[x];
			for(int k=1;k<=25;k++) T[k].add(i,-b[k][a[i]]);
			a[i] = x;
			for(int k=1;k<=25;k++) T[k].add(i,b[k][a[i]]);
		}else{
			int l = read(),r = read(),x = read();
			if(chk(l,r,x)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

