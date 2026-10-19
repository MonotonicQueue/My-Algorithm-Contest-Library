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
int n,lst,tot=1,ans;
struct Node{
	int len,fail;
	ll cnt;
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
		t[tot].cnt = t[t[tot].fail].cnt+1;
	}
	lst = t[pos].son[c];
	ans = t[lst].cnt;
	printf("%d ",ans);
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	t[0].fail = 1; t[1].len = -1;
	for(int i=1;i<=n;i++){
		if(i != 1) s[i] = (s[i]-97+ans)%26+97;
		insert(i);
	}
	return 0;
} 