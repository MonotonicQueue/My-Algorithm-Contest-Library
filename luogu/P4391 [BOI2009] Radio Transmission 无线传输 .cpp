#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read() {
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) {
		X = X*10+ch-'0';
		ch = getchar();
	}
	return X*r;
}
const int N = 1e6+10;
int n; char s[N];
int nxt[N];
int main() {
	n = read();
	scanf("%s",s);
	nxt[0] = 0; nxt[1] = 0;
	for(int i=1;i<n;i++){
		int j = nxt[i];
		while(j && s[i] != s[j]) j = nxt[j];
		if(s[i] == s[j]) nxt[i+1] = j+1;
		else nxt[i+1] = 0;
	}
	printf("%d",n-nxt[n]);
	return 0;
}