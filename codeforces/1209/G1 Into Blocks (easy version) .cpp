#include<bits/stdc++.h>
#define ll long long
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
int n,q;
int a[N];
int cnt[N],L[N],R[N];
int main(){
	n = read(); q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	if(!q){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
			if(!L[a[i]]) L[a[i]] = i;
			R[a[i]] = i;
		}
		int l = 1,r = 1;
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(i > r || i == n){
				int res = 0;
				for(int j=l;j<=r;j++) res = max(res,cnt[a[j]]);
				ans += r-l+1-res;
				l = r = i;
			}
			r = max(r,R[a[i]]);
		}
		cout << ans;
	}
	return 0;
}
/*
5 0
1 2 1 2 1
2 1
4 1
5 3
2 3
4 2
2 1
 */























