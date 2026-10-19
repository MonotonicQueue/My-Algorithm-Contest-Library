#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0 ,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 20;
const int M = 1<<16;
const int inf = 1e9;
int k,n;
int p[N],w[N],sum[M];
double ans[110][M];
int main(){
	k = read(); n = read();
	for(int i=1;i<=n;i++){
		p[i] = read();
		int x = read();
		while(x){
			w[i] |= (1<<(x-1));
			x = read();
		}
	}
	int num = (1<<n)-1;
	for(int i=k;i;i--){
		for(int j=0;j<=num;j++){
			for(int x=1;x<=n;x++){
				if((j | w[x]) == j)
					ans[i][j] += max(ans[i+1][j],ans[i+1][j|(1<<(x-1))]+p[x]);
				else ans[i][j] += ans[i+1][j];
			}
			ans[i][j] /= n;
		}
	}
	printf("%.6lf",ans[1][0]);
	return 0;
} 