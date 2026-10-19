#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAX = 1e5+10;
int n,m;
string op[MAX];
int t[MAX];
int calc(int bit,int val){
	for(int i=1;i<=n;i++){
		int x = (t[i]>>bit)&1;
		if(op[i] == "AND") val=val&x;
		else if(op[i] == "OR") val=val|x;
		else val=val^x;
	}
	return val;
}
int main(){
	//ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> op[i] >> t[i];
	int val=0,ans=0;
	for(int bit=29;bit>=0;bit--){
		int res0 = calc(bit,0);
		int res1 = calc(bit,1);
		if(val+(1<<bit) <= m && res0 < res1)
			val+=(1<<bit),ans+=res1<<bit;
		else
			ans+=res0<<bit;
	}
	cout << ans;
	return 0;
}