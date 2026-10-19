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
const int N = 1e5+10;
char s[N];
int cnt[20],n,m=1e5,pw[10] = {1,10,100,1000,10000,100000,1000000};
int nxt[N][11],t[N];
ll v[20],ans;
void work(int x){
	ll sum = x;
	for(int i=1;i<=9;i++) t[i] = 0;
	int pos = n+1;
	while(x){
		int num = x%10;
		x /= 10;
		t[num]++;
		pos = nxt[pos-1][num];
	}
	if(!pos) return ;
	for(int i=1;i<=9;i++) sum += v[i]*(cnt[i]-t[i]);
	ans = min(ans,sum);
}
int main(){
	// freopen("bargain.in","r",stdin);
	// freopen("bargain.out","w",stdout);
    int C = read(),T = read();
	while(T--){
		scanf("%s",s+1);
		n = strlen(s+1);
		for(int i=1;i<=9;i++) cnt[i] = 0;
		v[0] = 1e9;
		for(int i=1;i<=9;i++) v[i] = read();
		for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
		for(int i=1;i<=9;i++) nxt[0][i] = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=9;j++) nxt[i][j] = nxt[i-1][j];
			nxt[i][s[i]-'0'] = i;
		}
		ans = 1e18;
		for(int i=0;i<=m;i++) work(i);
		cout << ans << "\n";
	}
    return 0;
}
