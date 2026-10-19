#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n,ans;
int a[N][N],t[N];
bool chk(){
	for(int i=1;i<=n;i++){
		int cnt = 0,pre = 0;
		for(int j=1;j<=5;j++){
			if(a[i][j] != t[j]){
				cnt++;
				if(cnt > 2) return false;
				if(cnt == 2 && ((a[i][j]-t[j]+10)%10 != (a[i][pre]-t[pre]+10)%10 || pre != j-1)) return false;
				pre = j;
			}
		}
		if(!cnt) return false;
	}
	return true;
}
void dfs(int x){
	if(x > 5){
		ans += chk();
		return ;
	}
	for(int i=0;i<=9;i++){
		t[x] = i;
		dfs(x+1);
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin >> a[i][j];
	dfs(1);
	cout << ans;
	return 0;
} 
/*
1
0 0 1 1 5
*/