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
int n;
int a[N],cnt;
char s[N];
void work(int x){
	cnt = 0;
	for(int i=1;i*i<=x;i++){
		if(x % i == 0){
			a[++cnt] = i;
			if(i*i != x) a[++cnt] = x/i;
		}
	}
	sort(a+1,a+1+cnt);
//	for(int i=1;i<=cnt;i++) cout << a[i] << " ";cout << "\n";
}
bool chk(int x){
	int d = 0;
	for(int i=1;i<n/x;i++){
		for(int j=1;j<=x;j++) if(s[j] != s[i*x+j]) d++;
		if(d > 1) return false;
	} 
	return true;
}
signed main(){
	int T = read();
	while(T--){
		n = read();
		scanf("%s",s+1);
		work(n);
		int ans = n;
		for(int i=1;i<=cnt;i++) if(chk(a[i])){
			ans = min(ans,a[i]);
			break;
		}
		reverse(s+1,s+1+n);
		for(int i=1;i<=cnt;i++) if(chk(a[i])){
			ans = min(ans,a[i]);
			break;
		}
		cout << ans<< "\n";
	}
	return 0;
}