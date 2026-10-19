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
const int N = 2e5+10;
int n;
char s[N];
int main(){
	int T = read();
	while(T--){
		n = read();
		scanf("%s",s+1);
		int cnt1 = 0,cnt2 = 0;
		for(int i=1;i<=n;i++){
			if(s[i] == '1') cnt1++;
			else if(s[i-1] != '0') cnt2++;
		}
		puts(cnt1 > cnt2 ? "YES" : "NO");
	}
	return 0;
}