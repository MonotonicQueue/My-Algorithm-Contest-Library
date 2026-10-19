#include<bits/stdc++.h>
using namespace std;
const int MAX = 10;
int n,mp[MAX][MAX],f[MAX][MAX][MAX][MAX];
int main(){
	cin >> n;
	for(int i=1;;i++){
		int x,y,z;
		cin >> x >> y >> z;
		if(x == 0 && y == 0 && z == 0) break;
		mp[x][y] = z;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++){
					f[i][j][k][l]=max(f[i-1][j][k-1][l],max(f[i-1][j][k][l-1],max(f[i][j-1][k-1][l],f[i][j-1][k][l-1])))+mp[i][j]+mp[k][l];
					if(i == k && j == l) f[i][j][k][l]-=mp[i][j];
				}	
	cout << f[n][n][n][n];
	return 0;
}