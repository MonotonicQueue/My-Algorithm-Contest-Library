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
const int N = 1e6+10;
int n,lst,tot=1;
struct Node{
	int len,fail,cnt;
	int son[26];
}t[N];
char s[N];
int getfail(int x,int i){
	while(s[i-t[x].len-1] != s[i]) x = t[x].fail;
	return x;
}
void insert(int x){
	int pos = getfail(lst,x),c = s[x]-'a';
	if(!t[pos].son[c]){
		t[++tot].fail = t[getfail(t[pos].fail,x)].son[c];
		t[pos].son[c] = tot;
		t[tot].len = t[pos].len+2;
	}
	lst = t[pos].son[c];
	t[lst].cnt++;
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	t[0].fail = 1; t[1].len = -1;
	for(int i=1;i<=n;i++) insert(i);
	ll ans = 0;
	for(int i=tot;i>=1;i--) t[t[i].fail].cnt += t[i].cnt;
	for(int i=2;i<=tot;i++) ans = max(ans,(ll)t[i].cnt*t[i].len);
	printf("%lld",ans);
	return 0;
} 