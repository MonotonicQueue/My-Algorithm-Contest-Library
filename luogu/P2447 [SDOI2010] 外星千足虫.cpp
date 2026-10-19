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
const int N = 2100;
int n,m;
char ch[N];
bitset<1010>a[N];
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=n;j++)
			a[i][j] = ch[j]-'0';
		a[i][n+1] = read();
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int k = i;
		while(k<=m && !a[k][i]) k++;
		if(k > m){
			puts("Cannot Determine");
			return 0;
		}
		ans = max(ans,k);
		swap(a[i],a[k]);
		for(int j=1;j<=m;j++){
			if(j != i && a[j][i])
				a[j] = a[j]^a[i];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(a[i][n+1]) puts("?y7M#");
		else puts("Earth");
	return 0;
}