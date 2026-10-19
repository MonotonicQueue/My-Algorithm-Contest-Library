#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
int num[N];
ll cnt[N],C[N][N];
ll work(int n){
	ll ans = 1;
	for(int i=0;i<=9;i++){
		ans *= C[n][cnt[i]];
		n -= cnt[i];
	}
	return ans;
}
int main(){
	string s;
	cin >> s;
	int len = s.size();
	for(int i=0;i<s.size();i++){
		num[i+1] = s[i]-'0';
		cnt[num[i+1]]++;
	}
	C[0][0] = 1;
	for(int i=1;i<=len;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	}
	ll ans = 0;
	for(int i=1;i<=len;i++){
		for(int j=0;j<num[i];j++){
			if(cnt[j]){
				cnt[j]--;
				ans += work(len-i);
				cnt[j]++;
			}
		} 
		cnt[num[i]]--;
	}
	cout << ans;
	return 0;
}