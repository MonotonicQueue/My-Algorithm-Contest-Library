#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e6+10;
int	n,m,type[N];
char s[2][N];
int solve(){
	int ans = 0,sum = 0;
	for(int i=1;i<=n;i++){
		if(s[0][i] == '1' && s[1][i] == '1') type[i] = 1;
		if(s[0][i] == '0' && s[1][i] == '0') type[i] = 2;
		if(s[0][i] == '1' && s[1][i] == '0') type[i] = 3;
		if(s[0][i] == '0' && s[1][i] == '1') type[i] = 4;
	}
	for(int i=1;i<=n;i++){
		if(type[i] == 1) sum += 2;
		if(type[i] == 2) sum--;
		ans = max(ans,sum);
		sum = max(sum,0);
	}
	sum = 0;
	int flag = 3;
	for(int i=1;i<=n;i++){
		if(type[i] == 1) flag = 3,sum += 2;
		else if(type[i] == 2) sum--;
		else if(type[i] == 3){
			if(flag & 1){
				flag = 1;
				sum++;
			}else flag = 3;
		}else{
			if(flag & 2){
				flag = 2;
				sum++;
			}else flag = 3;
		}
		ans = max(ans,sum-2*m);
		if(sum <= 0) sum = 0,flag = 3;
	}
	return ans;
}
int main(){
//	freopen("summer.in","r",stdin);
//	freopen("summer.out","w",stdout);
	int C = read(),T = read();
	while(T--){
		n = read(); m = read();
		scanf("%s",s[0]+1);
		scanf("%s",s[1]+1);
		cout << solve() << "\n";
	}
	return 0;
}