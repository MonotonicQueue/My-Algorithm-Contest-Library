#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
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
int n;
char s[N];
int kmp[N],Z[N],cnt[N];
inline void work_kmp(){
	for(int i=1;i<=n;i++) cnt[i] = 1;
	for(int i=2,j=0;i<=n;i++){
		while(j && s[j+1] != s[i]) j = kmp[j];
		if(s[j+1] == s[i]) j++;
		kmp[i] = j;
	}
	for(int i=n;i;i--) cnt[kmp[i]] += cnt[i];
}
int ans;
inline void work_exkmp(){
	Z[1] = n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i <= r) Z[i] = min(Z[i-l+1],r-i+1);
		while(i+Z[i] <= n && s[i+Z[i]] == s[1+Z[i]]) Z[i]++;
		if(i+Z[i]-1 > r) r = i+Z[i]-1,l = i;
	}
	for(int i=1;i<=n;i++) if(Z[i] == n-i+1) ans++;
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	work_kmp();  work_exkmp();
	cout << ans << "\n";
	for(int i=n;i;i--)
		if(Z[i] == n-i+1) cout << n-i+1 << " " << cnt[n-i+1] << "\n";
	return 0;
}