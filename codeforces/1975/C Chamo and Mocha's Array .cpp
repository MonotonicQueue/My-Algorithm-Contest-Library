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
const int N = 1e5+10;
int n,a[N];
bool chk(int x){
	int len = 0,now = 0;
	for(int i=1;i<=n;i++){
		if(a[i] >= x) now++;
		else now--;
		len++;
		if(now < 0) now = 0,len = 0;
		if(len > 1 && now > 0) return true;
	}
	return false;
}
int main(){
	int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        int l = 1,r = 1e9,ans = 0;
		while(l <= r){
			int mid = (l+r)>>1;
			if(chk(mid)) l = mid+1,ans = mid;
			else r = mid-1;
		}
		cout << ans << "\n";
    }
	return 0;
}

