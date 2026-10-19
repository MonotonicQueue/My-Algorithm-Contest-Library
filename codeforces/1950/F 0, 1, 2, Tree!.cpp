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
const int N = 1e6+10;
int a,b,c;
int f[N];
signed main(){
	int T = read();
	while(T--){
		cin >> a >> b >> c;
		if(2*a+b != a+b+c-1){
			puts("-1");
			continue;
		}
		int h = 0,sum = 1;
		bool flag = false;
		while(!flag){
			h++;
			int cnt = 0;
			while(sum--){
				if(a) a--,cnt+=2;
				else if(b) b--,cnt+=1;
				else if(c) c--;
				else {
					flag = true;
					break;
				}
			}
			sum = cnt;
			if(!cnt) break;
		}
		printf("%d\n",h-1);
	}
	return 0;
}