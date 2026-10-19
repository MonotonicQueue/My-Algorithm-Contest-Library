#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 2e5+10;
int n,a[N],b[N],m;
bool flag[N];
vector<int> v[N];
signed main(){
	int T = read();
	while(T--){
		n = read(); m = 0;
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[++m] = a[i];
        sort(b+1,b+1+m);
        m = unique(b+1,b+1+m)-b-1;
        for(int i=1;i<=n;i++) a[i] = lower_bound(b+1,b+1+m,a[i])-b;
        for(int i=1;i<=m;i++) v[i].clear();
        for(int i=1;i<=n;i++) v[a[i]].push_back(i),flag[i] = false;
        flag[n+1] = flag[0] = 0;
        
	}
    return 0;
}
