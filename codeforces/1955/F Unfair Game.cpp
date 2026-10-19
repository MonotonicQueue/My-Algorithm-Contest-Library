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
int p[5],sum;
signed main(){
	int T = read();
	while(T--){
		for(int i=1;i<=4;i++) p[i] = read();
		sum = 0;
		for(int i=1;i<=4;i++) if(p[i] & 1) sum ^= i;
		int ans = 0;
		if(sum >= 4) sum ^= 4,p[4]--;
		if(sum == 3){
			if(p[3]) p[3]--,ans++,sum = 0;
			else if(p[1] && p[2]) p[1]--,p[2]--,ans++,sum = 0;
		}else if(sum == 2){
			if(p[2]) p[2]--,ans++,sum = 0;
			else if(p[1] && p[3]) p[1]--,p[3]--,ans++,sum = 0;
		}else if(sum == 1){
			if(p[1]) p[1]--,ans++,sum = 0;
			else if(p[2] && p[3]) p[2]--,p[3]--,ans++,sum = 0;
		}else ans++;
		if(sum){
			printf("0\n");
			continue;
		}
		ans += p[4]/2; p[4] = 0;
		ans += p[3]/2+p[2]/2+p[1]/2;
		if(p[3] % 2 == 0 && p[2] % 2 == 0 && p[1] % 2 == 0) ans--;
		cout << ans << "\n" ;
	}
	return 0;
}