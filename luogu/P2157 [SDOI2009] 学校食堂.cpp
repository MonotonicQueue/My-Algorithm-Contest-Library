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
const int N = 1010;
int n,T[N],B[N];
int f[N][1<<8][20];
int main(){
	int C = read();
	while(C--){
		n = read();
		for(int i=1;i<=n;i++){
			T[i] = read();
			B[i] = read();
		}
		memset(f,0x3f,sizeof(f));
		f[1][0][7] = 0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<(1<<8);j++)
				for(int k=-8;k<=7;k++) if(f[i][j][k+8] != 0x3f3f3f3f)
					if(j & 1) f[i+1][j>>1][k+7] = min(f[i+1][j>>1][k+7],f[i][j][k+8]);
					else{
						int lim = n+10;
						for(int h=0;h<=7;h++) if(!((j >> h) & 1)){
							lim = min(lim,i+h+B[i+h]);
							if(i+h > lim) continue;
							f[i][j|(1<<h)][h+8] = min(f[i][j|(1<<h)][h+8],f[i][j][k+8]+(i+k ? (T[i+k]^T[i+h]) : 0));
						}
					}
		int ans = 2e9;
		for(int i=0;i<=7;i++) ans = min(ans,f[n+1][0][i]);
		cout << ans << "\n";
	}
    return 0;
}
