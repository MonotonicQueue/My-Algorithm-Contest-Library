#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 30;
int n,sg[N];
bool s[1100];
void getSG(){
	sg[0] = 0;
	for(int i=1;i<=21;i++){
		memset(s,0,sizeof(s));
		for(int j=i-1;j>=0;j--)
			for(int k=j;k>=0;k--)
				s[sg[j]^sg[k]] = 1;
		for(int j=0;j<=1000;j++)
			if(!s[j]){
				sg[i] = j;
				break;
			}
	}
}
int main(){
	getSG();
	int T = read();
	while(T--){
		n = read();
		int ans = 0;
		for(int i=n-1,x;i>=0;i--) if((x = read()) & 1) ans ^= sg[i];
		if(!ans){
			puts("-1 -1 -1");
			puts("0");
			continue;
		}
		int cnt = 0,a,b,c;
		for(int i=n-1;i>=0;i--)
			for(int j=i-1;j>=0;j--)
				for(int k=j;k>=0;k--){
					if((ans^sg[i]^sg[j]^sg[k]) == 0){
						if(!cnt) a = n-i-1,b = n-j-1,c = n-k-1;
						cnt++;
					}
				}
		printf("%d %d %d\n%d\n",a,b,c,cnt);
	}
	return 0;
}
