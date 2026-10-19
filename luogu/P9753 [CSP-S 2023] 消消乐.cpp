#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 2e6+10;
int n,lst[N];
ll f[N],ans;
char ch[N]; 
int find(int x,char c){
	if(ch[x] == c) return x;
	if(!lst[x]) return 0;
	return find(lst[x]-1,c);
}
int main(){
	n = read();
	scanf("%s",ch+1);
	for(int i=2;i<=n;i++){
		lst[i] = find(i-1,ch[i]);
		if(lst[i]) f[i] = f[lst[i]-1]+1;
	}
	for(int i=1;i<=n;i++) ans += f[i];
	cout << ans;
	return 0;
}