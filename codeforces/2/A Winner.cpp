#include<bits/stdc++.h>
using namespace std;
int n,cnt;
map<string,int> a,b;
string name[1010];
int score[1010];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int maxn = 0; string ans;
	for(int i=1;i<=n;i++){
		cin >> name[i] >> score[i];
		a[name[i]] += score[i];
	}
	for(int i=1;i<=n;i++)
		maxn = max(maxn,a[name[i]]);
	for(int i=1;i<=n;i++){
		b[name[i]] += score[i];
		if(a[name[i]] == maxn && b[name[i]] >= maxn){
			ans = name[i];
			break;
		}
	}
	cout << ans;
	return 0;
}