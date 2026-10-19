#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	ll X = 0 , f = 1;
	if(ch == '-') f = -1 , ch = getchar();
	while(isdigit(ch)) X = (X<<1)+(X<<3)+ch-'0' , ch = getchar();
	return X*f;
}

const int N = 210;
int n,m;
int t[N];
int f[N][N]; bool vis[N];

int main(){
	n = read(); m = read();
	for(int i=0;i<n;i++)
		t[i] = read();
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		int u,v,w;
		u = read(); v = read(); w = read();
		f[u][v] = f[v][u] = w;
	}
	for(int i=0;i<n;i++) f[i][i] = 0;
	int Q = read();
	while(Q--){
		int x,y,day;
		x = read();  y = read(); day = read();
		for(int k=0;k<n;k++)
			if(!vis[k] && t[k] <= day){
				vis[k] = true;
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
							f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		if(f[x][y] == 0x3f3f3f3f || t[x]>day || t[y]>day) cout << "-1\n";
		else cout << f[x][y] << "\n";
	}
	return 0;
}