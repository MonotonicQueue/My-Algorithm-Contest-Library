#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 32010 , M = 80;
int n,m,p[M],v[M],q[M];
vector <int> a[M];
int dp[N];//用了N元钱
signed main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> v[i] >> p[i] >> q[i];
		if(q[i]) a[q[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
		for(int j=n;j>=v[i];j--){
			if(q[i]) break;
			if(dp[j-v[i]]+v[i]*p[i] >= dp[j])
			dp[j] = dp[j-v[i]]+v[i]*p[i];
			if(a[i].size() == 0) continue;
			int id = a[i][0];
			if(j-v[i]-v[id] >= 0)
				dp[j] = max(dp[j],dp[j-v[i]-v[id]]+v[i]*p[i]+v[id]*p[id]);
			if(a[i].size() == 1) continue;
			int iid = a[i][1];
			if(j-v[i]-v[iid] >= 0)
				dp[j] = max(dp[j],dp[j-v[i]-v[iid]]+v[i]*p[i]+v[iid]*p[iid]);
			if(j-v[i]-v[id]-v[iid] >= 0)
				dp[j] = max(dp[j],dp[j-v[i]-v[id]-v[iid]]+v[i]*p[i]+v[id]*p[id]+v[iid]*p[iid]);
		}
	cout << dp[n];
	return 0;
}

