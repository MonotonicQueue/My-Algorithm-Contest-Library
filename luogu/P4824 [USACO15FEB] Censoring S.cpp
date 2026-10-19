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
int n,m,top; char s[N],t[N];
int nxt[N],pre[N],stk[N];
int main() {
	scanf("%s",s); n = strlen(s);
	scanf("%s",t); m = strlen(t);
	nxt[0] = 0; nxt[1] = 0;
	for(int i=1;i<m;i++){
		int j = nxt[i];
		while(j && t[i] != t[j]) j = nxt[j];
		if(t[i] == t[j]) nxt[i+1] = j+1;
		else nxt[i+1] = 0;
	}
	for(int i=0,j=0;i<n;i++){
		while(j && s[i] != t[j]) j = nxt[j];
		if(s[i] == t[j]) j++;
		stk[++top] = i; pre[i] = j;
		if(j == m){
			top -= m;
			j = pre[stk[top]];
		}
	}
	for(int i=1;i<=top;i++) putchar(s[stk[i]]);
	return 0;
}