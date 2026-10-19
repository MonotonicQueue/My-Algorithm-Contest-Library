#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 2e6+10;
int n,m,k;
int a[N],b[N],raw[N],cnt;
bool vis[N];
bool chk(){
	for(int i=1;i<=n;i++){
		k = max(k,a[i]);
		if(vis[a[i]] && a[i] != a[i-1]) return false;
		if(!vis[a[i]]) raw[a[i]] = ++cnt;
		vis[a[i]] = true;
	}
	for(int i=1;i<=n;i++) a[i] = raw[a[i]];
	for(int i=1;i<=m;i++) b[i] = raw[b[i]];
	return true;
}
int t[N<<1];
inline void change(int x,int y){
    x += N;
    while(x < 2*N){
        t[x] = max(t[x],y);
        x += x&(-x);
    }
}
int query(int x){
    x += N;
    int res = -1e9;
    while(x){
        res = max(res,t[x]);
        x -= x&(-x);
    }
    return res;
}
pii c[N];
signed main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++) b[i] = read();
	if(!chk()){
		puts("-1");
		return 0;
	}
	memset(t,0xcf,sizeof(t));
    for(int i=1;i<=m;i++) c[i] = mk(b[i],i-b[i]);
    sort(c+1,c+1+m);
	int res = 0;
    change(0,0);
    for(int i=1;i<=m;i++){
        int j = c[i].fi+c[i].se;
        int rs = query(c[i].se);
        change(c[i].se,rs+1);
        if(m-j >= k-b[j]) res = max(res,rs+1);
    }
    cout << m-res;
	return 0;
}

//g++ -std=c++14 -O2 -o 1st 1st.cpp