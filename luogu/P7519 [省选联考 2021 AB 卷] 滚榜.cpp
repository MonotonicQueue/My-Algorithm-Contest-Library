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
const int N = 20;
int n,m,a[N];
ll f[1<<13][13][510];
int len[1<<13];
int main(){
	n = read(); m = read();
	for(int i=0;i<n;i++) a[i] = read();
	for(int i=0;i<(1<<n);i++) len[i] = len[i>>1]+(i & 1);
	int pos = 0,mx = a[0];
	for(int i=1;i<n;i++) if(a[i] > mx) mx = a[i],pos = i;
	for(int i=0;i<n;i++){
		int sum = (mx-a[i]+(i>pos))*n;
		if(sum <= m) f[1<<i][i][sum] = 1;
	}
	for(int s=1;s<(1<<n);s++){
		vector<int> v1,v2;
		for(int i=0;i<n;i++)
			if((s >> i) & 1) v1.push_back(i);
			else v2.push_back(i);
		for(int x : v1) for(int i=0;i<=m;i++) if(f[s][x][i]){
			for(int y : v2){
				int sum = max(0,a[x]-a[y]+(x<y));
				if(i+sum*(n-len[s]) <= m) f[s|(1<<y)][y][i+sum*(n-len[s])] += f[s][x][i];
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<n;i++) for(int j=0;j<=m;j++) ans += f[(1<<n)-1][i][j];
	cout << ans;
    return 0;
}