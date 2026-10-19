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
map<pair<pii,int>,bool> mp;
int main(){
	int n = read();
	while(n--){
		int x = read(),y = read();
		mp[mk(mk(x,y),1)] = 1;
		mp[mk(mk(x,y),4)] = 1;
		mp[mk(mk(x,y+1),3)] = 1;
		mp[mk(mk(x,y+1),4)] = 1;
		mp[mk(mk(x+1,y),1)] = 1;
		mp[mk(mk(x+1,y),2)] = 1;
		mp[mk(mk(x+1,y+1),2)] = 1;
		mp[mk(mk(x+1,y+1),3)] = 1;
	}
	printf("%.9lf",mp.size()*0.25);
	return 0;
}