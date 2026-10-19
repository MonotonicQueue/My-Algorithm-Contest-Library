#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 5199;
const int M = 1e6+10;
int n;
char ch[N];
int t[N];
void add(int x,int y){
	while(x <= n){
		t[x] += y;
		x += x&(-x);
	}
}
int ask(int x){
	int res = 0;
	while(x){
		res += t[x];
		x -= x&(-x);
	}
	return res;
}
bool chk(int k){
	if(k == 1) return true;
	for(int i=1;i<=n;i++) t[i] = 0;
	for(int i=1;i<=n;i++)
		if(ch[i] == '1') add(i,1),add(i+1,-1);
	for(int i=1;i+k-1<=n;i++)
		if(ask(i) % 2 == 0) add(i,1),add(i+k,-1);
	for(int i=n;i>=1;i--)
		if(ask(i) % 2 == 0) return false;
	return true;
}
signed main(){
	int T = read();
	while(T--){
		n = read();
		scanf("%s",ch+1);
		for(int i=n;i>=1;i--){
			if(chk(i)){
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}