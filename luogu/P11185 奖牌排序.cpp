#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int N = 2e5+10;
int n,ans[N];
int g[N],s[N],b[N],a[N];
void work(int *c){
	for(int i=1;i<=n;i++) a[i] = c[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int pos = upper_bound(a+1,a+1+n,c[i])-a-1;
		ans[i] = min(ans[i],n-pos+1);
	}
}
int main(){
	n = read();
	for(int i=1;i<=n;i++){
		g[i] = read();
		s[i] = read();
		b[i] = read();
		ans[i] = n;
	}
	work(g); work(s); work(b);
	for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}
