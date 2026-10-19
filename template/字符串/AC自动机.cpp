#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10000;
int n,len,tot;
struct Node{
	int son[26];
	int end,fail;
}t[N];
void insert(char ch[]){
	int p = 0,lench = strlen(ch+1);
	for(int i=1;i<=lench;i++){
		int c = ch[i]-'a';
		if(!t[p].son[c]) t[p].son[c] = ++tot;
		p = t[p].son[c];
	}
	t[p].end++;
}
void getFail(){
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
char ch[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		int lench = strlen(ch+1);
		insert(ch);
	}
	getFail();
	
	return 0;
} 
