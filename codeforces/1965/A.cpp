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
const int N = 2e5+10;
int n,a[N];
int flag[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read(),flag[i] = false;
		sort(a+1,a+1+n); n = unique(a+1,a+1+n)-a-1;
		for(int i=n;i;i--) a[i] = a[i]-a[i-1];
		flag[n] = 1;
		for(int i=n-1;i;i--){
			if(a[i] == 1){
				if(flag[i+1] == 1) flag[i] = 2;
				if(flag[i+1] == 2) flag[i] = 1;
			}else{
				flag[i] = 1;
			}
		}
		puts(flag[1] == 1 ? "Alice" : "Bob");
	}
	return 0;
}