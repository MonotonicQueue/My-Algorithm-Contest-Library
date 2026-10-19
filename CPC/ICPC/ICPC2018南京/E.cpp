#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1e6+10;
int n,k;
char s[2][N];
int stk[2][N],top[2],a[2][N];
void work(char *s,int *stk,int &top,int *a){
	a[0] = -1;
	for(int i=1;i<=n;i++){
		if(a[top] == s[i]-'0') stk[top]++;
		else stk[++top] = 1,a[top] = s[i]-'0';
		if(stk[top] == k) top--;
	}
}
int main(){
	n = read(); k = read();
	for(int op=0;op<=1;op++){
		scanf("%s",s[op]+1);
		work(s[op],stk[op],top[op],a[op]);
	}
	bool flag = top[0] == top[1];
	for(int i=1;i<=top[0];i++){
		flag &= (a[0][i] == a[1][i]) && (stk[0][i] == stk[1][i]);
	}
	puts(flag ? "Yes" : "No");
	return 0;
}