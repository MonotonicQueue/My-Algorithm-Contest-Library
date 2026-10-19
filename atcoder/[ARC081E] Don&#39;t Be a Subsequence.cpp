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
const int N = 2e5+10;
int n,nxt[N][26],f[N];
char s[N];
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i=0;i<26;i++) nxt[n+1][i] = n+1;
	for(int i=n;i;i--){
		for(int j=0;j<26;j++) nxt[i][j] = nxt[i+1][j];
		nxt[i][s[i]-'a'] = i;
	}
	f[n+1] = 1;
	for(int i=n;i;i--){
		f[i] = 1e9;
		for(int j=0;j<26;j++)
			f[i] = min(f[i],f[nxt[i][j]+1]+1);
	}
	int x = 1;
	while(x <= n){
		for(int i=0;i<26;i++)
			if(f[x] == f[nxt[x][i]+1]+1){
				putchar('a'+i);
				x = nxt[x][i]+1;
				break;
			}
	}
    return 0;
}