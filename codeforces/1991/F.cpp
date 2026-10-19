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
const int N = 1e5+10;
int n,q,a[N];
int b[N],tot;
void solve(){
	for(int i=1;i+5<=tot;i++){
		if(b[i]+b[i+1] <= b[i+2]) continue;
		for(int j=i+3;j+2<=tot;j++)
			if(b[j]+b[j+1] > b[j+2]){
				puts("YES");
				return ;
			}
	}
	for(int i=1;i+5<=tot;i++) for(int x=i;x<=i+5;x++)
	for(int y=x+1;y<=i+5;y++) for(int z=y+1;z<=i+5;z++)
		if(b[x]+b[y] > b[z]){
			int t[6] = {1,1,1,1,1,1};
			t[x-i] = t[y-i] = t[z-i] = 0;
			int ct = 0,s = 0;
			for(int j=0;j<5;j++){
				if(!t[j]) continue;
				ct++;
				if(ct != 3) s += b[j+i];
				else if(s > b[i+j]){
					puts("YES");
					return ;
				}
			}
		}
	puts("NO");
}
int main(){
	n = read(); q = read();
	for(int i=1;i<=n;i++) a[i] = read();
	while(q--){
		int l = read(),r = read();
		if(r-l+1 >= 48){
			puts("YES");
			continue;
		}
		tot = 0;
		for(int i=l;i<=r;i++) b[++tot] = a[i];
		sort(b+1,b+1+tot);
		solve();
	}
	return 0;
}
