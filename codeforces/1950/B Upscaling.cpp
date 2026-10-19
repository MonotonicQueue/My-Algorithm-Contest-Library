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
signed main(){
	int T = read();
	while(T--){
		int n = read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((i+j) & 1) printf("..");
				else	    printf("##");
			}
			printf("\n");
			for(int j=1;j<=n;j++){
				if((i+j) & 1) printf("..");
				else	    printf("##");
			}
			printf("\n");
		} 
	}
	return 0;
}