#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,k,a[N],cnt[N],d[N];
int dis(int x,int y){
	if(x > y) swap(x,y);
	return min(y-x,x-y+k);
}
void solve(){
	k = read(); n = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1,j=1;i<=n;i++){
		while(dis(a[i],a[j]) <= dis(a[i],a[j%n+1])){
			if(dis(a[i],a[j]) == dis(a[i],a[j%n+1]) && dis(i,j) != d[j])
				cnt[i]++,cnt[j]++;
			j = j%n+1;
		}
		d[i] = dis(a[i],a[j]);
		if(d[i] != d[j]) cnt[i]++,cnt[j]++;
	}
	if(n == 3){
		vector<int> v;
		v.push_back(a[2]-a[1]);
		v.push_back(a[3]-a[2]);
		v.push_back(a[1]+k-a[3]);
		sort(v.begin(),v.end());
		if(v[0] == v[1]) return puts("3"),void();
	}
	cout << *max_element(cnt+1,cnt+1+n) << "\n";
}
int main(){
	int T = 1;
	while(T--) solve();
	return 0;
}