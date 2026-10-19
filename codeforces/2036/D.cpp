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
const int N = 1e3+10;
int n,m,tot;
char s[N][N],t[N*N];
bool chk(int x){
    return t[x] == '1' && t[x+1] == '5' && t[x+2] == '4' && t[x+3] == '3';
}
void solve(){
	int sum = 0;
	n = read(); m = read();
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	tot = 0;
	for(int T=1;T<=min(n,m)/2;T++){
		int x = T,y = T;
		tot = 0;
		while(y < m-T+1) t[++tot] = s[x][y],y++;
		while(x < n-T+1) t[++tot] = s[x][y],x++;
		while(y > T) t[++tot] = s[x][y],y--;
		while(x > T) t[++tot] = s[x][y],x--;
		for(int i=tot+1;i<=tot+3;i++) t[i] = t[i-tot];
		for(int i=1;i<=tot;i++) sum += chk(i);
	}
	cout << sum << "\n";
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}