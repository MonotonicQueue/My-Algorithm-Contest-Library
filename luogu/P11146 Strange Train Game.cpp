#include<bits/stdc++.h>
#define ll __int128
#define mk make_pair
#define fi first
#define se second
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
int n,m;
char a[N],b[N];
set<int> s[N];
int sum[N],nxt[N];
int main(){
	n = read(); m = read();
	scanf("%s",a+1); scanf("%s",b+1);
	for(int i=1;i<=m;i++){
		int l = read(),r = read();
		s[l].insert(r);
	}
	for(int i=1;i<=n;i++){
		while(!s[i].empty() && *s[i].begin() < i){
			int x = *s[i].begin();
			s[i].erase(x);
		}
		if(a[i] != b[i]){
			if(s[i].empty()) continue;
			int x = *s[i].begin(); s[i].erase(x);
			nxt[i] = x;
			if(s[x+1].size() < s[i].size()) swap(s[i],s[x+1]);
			for(int y : s[i]) s[x+1].insert(y);
			s[i].clear();
		}else{
			if(s[i+1].size() < s[i].size()) swap(s[i],s[i+1]);
			for(int x : s[i]) s[i+1].insert(x);
			s[i].clear();
		}
	}
	for(int i=1;i<=n;i++){
		sum[i] += sum[i-1];
		if(sum[i] & 1) swap(a[i],b[i]);
		if(a[i] == '0' && b[i] == '1'){
			if(nxt[i]){
				sum[i]++; sum[nxt[i]+1]--;
				swap(a[i],b[i]);
			}
		}
	}
	for(int i=1;i<=n;i++) cout << a[i];
	return 0;
}
