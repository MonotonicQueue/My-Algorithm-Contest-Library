#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 700;
int n,x,cnt,minn = 99999;
int l[MAX]; bool ans;
int sum = 0,maxn = 0;
bool dfs(int now,int pos,int deg,int s){
	if(now == pos) return dfs(0,pos,maxn,s+1);
	if(s == x){
		cout << pos;
		exit(0);
	}
	for(int i=deg;i>=minn;i--){
		if(l[i] && now+i <= pos){
			l[i]--;
			dfs(now+i,pos,i,s);
			l[i]++;
			if(now == 0 || now+i == pos) break;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		int lll;
		cin >> lll;
		if(lll > 50) continue;
		l[lll]++;
		sum += lll;
		maxn = max(maxn,lll);
		minn = min(minn,lll);
	} n = cnt;
	for(int i=maxn;i<=sum/2;i++){
		if(sum % i != 0) continue;
		x = sum/i; dfs(0,i,maxn,0);
	}
	cout << sum;
	return 0;
}