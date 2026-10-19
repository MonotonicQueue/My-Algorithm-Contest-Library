#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3100;
int n,m;
char ch[N][N]; 
int maxn[N],minn[N];
bool chk(int x){
	for(int i=1;i<=n;i++){
		if(i == x) continue;
		if(minn[x] < maxn[i]) continue;
		if(minn[x] >= maxn[i]) return false;
	}
	return true;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++){
		maxn[i] = minn[i] = ch[i][1]-'a';
		for(int j=2;j<=m;j++) minn[i] = min(minn[i],int(ch[i][j]-'a'));
		for(int j=2;j<=m;j++) maxn[i] = max(maxn[i],int(ch[i][j]-'a'));
	}
	for(int i=1;i<=n;i++){
		if(chk(i)) printf("1");
		else printf("0");
	}
	return 0;
}