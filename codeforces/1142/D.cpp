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
const int N = 1e5+10;
int n;
char s[N];
ll f[N][11];
int calc(int x,int y){
	return (x*(x-1)/2+y+10)%11;
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		int c = s[i]-'0';
		for(int j=c+1;j<=10;j++) f[i][calc(j,c)] += f[i-1][j];
		if(c) f[i][c]++;
		for(int j=0;j<=10;j++) ans += f[i][j];
	}
	cout << ans;
    return 0;
}
