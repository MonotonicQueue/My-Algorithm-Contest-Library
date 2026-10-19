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
const int N = 2e4+10;
int n;
int main(){
	int T = read();
	while(T--){
		n = read();
		int ans = 0;
		for(int i=1;i<=n/2;i++){
			int x = read(),y = read();
			int s = (x-1)|(y-1);
			for(int k=0;k<32;k++)
				if((s >> k) % 2 == 0){
					ans ^= k;
					break;
				}
		}
		puts(ans ? "YES" : "NO");
	}
    return 0;
}
