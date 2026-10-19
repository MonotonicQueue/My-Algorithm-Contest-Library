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
const int N = 20;
int n;
string s[N][N];
map<char,int> mp;
int calc(string s){
	if(s.size() == 1) return mp[s[0]];
	return mp[s[0]]*(n-1)+mp[s[1]];
}
int main(){
	n = read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin >> s[i][j];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(s[j][i].size() == 2) mp[s[1][i][0]]++;
	bool flag = true;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(calc(s[1][i])+calc(s[j][1]) != calc(s[j][i])){
				flag = false;
				break;
			}
	if(!flag) cout << "ERROR!";
	else{
		for(int i=2;i<=n;i++)
			printf("%c=%d ",s[1][i][0],mp[s[1][i][0]]);
		printf("\n%d",n-1);
	}
    return 0;
}