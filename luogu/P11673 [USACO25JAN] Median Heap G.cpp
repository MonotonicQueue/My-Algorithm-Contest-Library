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
const int N = 2e5+10;
const ll inf = 1e18;
int n,Q,a[N],p[N];
ll c[N],f[N][3],ans[N];
int med(int x,int y,int z){
    if(x > y) swap(x,y);
    if(y > z) swap(y,z);
    if(x > y) swap(x,y);
    return y;
}
#define ls x<<1
#define rs x<<1|1
void merge(int x){
    ll cost[3] = {c[x],c[x],c[x]};
    cost[p[x]] = 0;
    if(x*2 > n){
        for(int i=0;i<3;i++) f[x][i] = cost[i];
        return ;
    }
    for(int i=0;i<3;i++) f[x][i] = inf;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                f[x][med(i,j,k)] = min(f[x][med(i,j,k)],f[ls][i]+f[rs][j]+cost[k]);
}
void update(int x,int s){
    p[x] = s;
    while(x){
        merge(x);
        x /= 2;
    }
}

int main(){
    n = read();
    vector<pii> v;
    for(int i=1;i<=n;i++){
        a[i] = read(),c[i] = read();
        v.emplace_back(a[i],-i);
        v.emplace_back(a[i]+1,-i-n);
    }
    Q = read();
    for(int i=1;i<=Q;i++){
        int x = read();
        v.emplace_back(x,i);
    }
    sort(v.begin(),v.end());
    for(int i=n;i;i--) merge(i);
    for(auto [x,op] : v){
        if(op > 0) ans[op] = f[1][1];
        else if(op >= -n) update(-op,1);
        else update(-op-n,2);
    }
    for(int i=1;i<=Q;i++) cout << ans[i] << "\n";
	return 0;
}