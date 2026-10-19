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
void write(__int128 x){
	if(!x) return ;
	write(x/10); putchar('0'+(x%10));
}
const int N = 85;
int T,n,a[N];
__int128 f[N][N],pw[N],ans;
int main(){
	T = read(); n = read();
	pw[0] = 1;
	for(int i=1;i<=n;i++) pw[i] = pw[i-1]*2;
	while(T--){
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++)
			for(int j=n;j>=i;j--){
				f[i][j] = 0;
				f[i][j] = max(f[i][j],f[i-1][j]+pw[n-(j-i+1)]*a[i-1]);
				f[i][j] = max(f[i][j],f[i][j+1]+pw[n-(j-i+1)]*a[j+1]);
			}
		__int128 mx = 0;
		for(int i=1;i<=n;i++) if(f[i][i]+pw[n]*a[i] > mx) mx = f[i][i]+pw[n]*a[i];
		ans += mx;
	}
	if(ans == 0) cout << "0";
	else write(ans);
    return 0;
}