#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n,tot;
struct Node{
	int son[26];
	int end,fail,len;
}t[N];
void insert(char ch[]){
	int p = 0,lench = strlen(ch+1);
	for(int i=1;i<=lench;i++){
		int c = ch[i]-'a';
		if(!t[p].son[c]) t[p].son[c] = ++tot;
		p = t[p].son[c];
	}
	t[p].end++; t[p].len = lench;
}
void build(){
	queue<int>q;
	for(int i=0;i<26;i++)
		if(t[0].son[i]) q.push(t[0].son[i]);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(t[x].son[i]){
				t[t[x].son[i]].fail = t[t[x].fail].son[i];
				q.push(t[x].son[i]);
			}else t[x].son[i] = t[t[x].fail].son[i];
	}
}
int stk[N],top,pre[N];
void query(char ch[]){
	int p = 0,lench = strlen(ch+1);
	for(int i=1;i<=lench;i++){
		int c = ch[i]-'a';
		while(p && !t[p].son[c]) p = t[p].fail;
		if(t[p].son[c]) p = t[p].son[c];
		pre[i] = p; stk[++top] = i;
		if(t[p].end){
			top -= t[p].len;
			p = pre[stk[top]];
		}
		//cout << p << "\n";
	}
}
char s[N],ch[N];
int main(){
	scanf("%s%d",s+1,&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		insert(ch);
	}
	build(); query(s);
	for(int i=1;i<=top;i++)
		putchar(s[stk[i]]);
	return 0;
} 