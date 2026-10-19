#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}

const int N = 25;
int n,m,ans;
int w[N*N],c[N],f[N][N],t[N][N],tti[N][N];
bool l[N][101000];
int main(){
	m=read(); n=read();
	for(int i=1;i<=n*m;i++) w[i] = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j] = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			t[i][j] = read();
	for(int i=1;i<=n*m;i++){
		c[w[i]]++;
		int cnt = 0;
		int id = f[w[i]][c[w[i]]],ti = t[w[i]][c[w[i]]];
		for(int j=tti[w[i]][c[w[i]]-1]+1;;j++){
			if(l[id][j] == 0) cnt++;
			else cnt = 0;
			if(cnt >= ti){
				ans = max(ans,j);
				tti[w[i]][c[w[i]]]=j;
				for(int k=0;k<ti;k++)
					l[id][j-k] = 1;
				break;
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=0;j<=11;j++)
		cout << l[i][j] << " ";
		cout << endl;
	}*/
		
	cout << ans;
	return 0;
}