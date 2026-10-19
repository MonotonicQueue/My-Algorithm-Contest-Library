#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 1e6+10;
int n,Q,a[N],t[N];
char s[N];
int son[N][3],fa[N],cnt;
inline void push_up(int x){
	int d[2] = {0,0};
	for(int i=0;i<3;i++)
		d[t[son[x][i]]]++;
	t[x] = d[0] < d[1];
}
void build(int x,int ft,int l,int r){
	// cout << x << " " << l << " " << r << "\n";
	fa[x] = ft;
	if(l == r){
		a[l] = x;
		return t[x] = s[l] == 'B',void();
	}
	int len = (r-l+1)/3;
	for(int i=0;i<3;i++){
		son[x][i] = ++cnt;
		build(son[x][i],x,l+i*len,l+(i+1)*len-1);
	}
	push_up(x);
}
int main(){
	n = read(); Q = read();
	scanf("%s",s+1);
	int len = strlen(s+1);
	++cnt;
	build(1,0,1,len);
	while(Q--){
		int x = read();
		x = a[x];
		t[x] ^= 1;
		x = fa[x];
		while(x) push_up(x),x = fa[x];
		if(t[1]) cout << "B\n";
		else cout << "A\n";
	}
    return 0;
}