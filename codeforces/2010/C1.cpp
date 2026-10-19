#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1e6+10;
int n;
char s[N];
int Z[N];
void getZ(){
	Z[1] = n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i <= r) Z[i] = min(Z[i-l+1],r-i+1);
		while(i+Z[i] <= n && s[i+Z[i]] == s[1+Z[i]]) Z[i]++;
		if(i+Z[i]-1 > r) r = i+Z[i]-1,l = i;
	}
}
void solve(){
	for(int i=2;i<=(n+1)/2;i++){
		if(Z[i] == n-i+1){
			cout << "YES\n";
			for(int j=i;j<=n;j++) cout << s[i];
			return ;
		}
	}
	cout << "NO";
}
int main(){
    scanf("%s",s+1);
	n = strlen(s+1);
	getZ();
	solve();
    return 0;
}
