#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
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
int n,a[N],R;
vector<int> ans;
int main(){
	n = read(); R = read();
	for(int i=1;i<=n;i++) a[i] = read();
	int c = a[(n+1)/2];
	for(int i=(n+1)/2;i>0;i--){
		if(a[i] == c) continue;
		int j = i;
		while(j > 1 && a[j-1] == a[j+1]) j--;
		// cout << i << " " << j << "\n";
		while(j <= i) ans.push_back(j),a[j] ^= 1,j++;
	}
	for(int i=(n+1)/2+1;i<=n;i++){
		if(a[i] == c) continue;
		int j = i;
		while(j < n && a[j-1] == a[j+1]) j++;
		while(j >= i) ans.push_back(j),a[j] ^= 1,j--;
	}
	// for(int i=1;i<=n;i++) cout << a[i] << " ";
	// cout << "\n";
	cout << ans.size() << "\n";
	for(int x : ans) cout << x << " ";
	return 0;
}
