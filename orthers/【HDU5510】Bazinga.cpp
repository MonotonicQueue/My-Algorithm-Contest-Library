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
const int N = 2100;
int n;
char ch[N][N];
int main(){
	int T = read();
	for(int ttt=1;ttt<=T;ttt++){
		n = read();
		for(int i=1;i<=n;i++) cin >> ch[i];
		int ans = -1;
		for(int l=1,r=2;r<=n;r++){
			while(l < r){
				if(!strstr(ch[r],ch[l])){
					ans = r;
					break;
				}
				l++;
			}
		}
		printf("Case #%d: %d\n",ttt,ans);
	}
	return 0;
}