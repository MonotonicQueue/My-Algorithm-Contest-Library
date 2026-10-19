#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define ll long long
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
int n,a[N],ans[N];
vector<int> v[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) v[a[i]].push_back(i);
    auto calc = [&](int x,int c)->int{
        int lst = -1e9,res = 0;
        for(int y : v[c])
            if(y-lst > x) res++,lst = y;
        return res;
    };
    int B = sqrt(n*__lg(n));
    for(int i=1;i<=n;i++){
        if(v[i].empty()) continue;
        for(int x=1;x<=B;x++){
            int t = calc(x,i);
            ans[x] += t; ans[x+1] -= t;
        }
        for(int x=B+1;x<=n;){
            int t = calc(x,i);
            int l = x,r = n,y = -1;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(t == calc(mid,i)) l = mid+1,y = mid;
                else r = mid-1;
            }
            ans[x] += t; ans[y+1] -= t;
            x = y+1;
        }
    }
    for(int i=1;i<=n;i++) ans[i] += ans[i-1];
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
	return 0;
}
