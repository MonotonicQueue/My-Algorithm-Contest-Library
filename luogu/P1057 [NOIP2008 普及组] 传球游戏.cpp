#include<bits/stdc++.h>
using namespace std;
int n,ans;
int f[35][35];
int dfs(int m,int id){
	if(id==0) id=n;
	if(id==n+1) id=1;
	if(f[m][id]!=-1) return f[m][id];
	if(m==0&&id==1){
		f[m][id]=1;
		return 1;
	}
	else if(m==0){
		f[m][id]=0;
		return 0;
	}
	f[m][id]=dfs(m-1,id+1)+dfs(m-1,id-1);
	return f[m][id];
}
int main(){
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	memset(f,-1,sizeof(f));
	cout << dfs(m,1);
	return 0;
}