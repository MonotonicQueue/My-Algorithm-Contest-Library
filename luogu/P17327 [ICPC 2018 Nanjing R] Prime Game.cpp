#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1e6+10;
int n,a[N];
int pr[N],cnt;
bool vis[N];
void init(int n = 1e6){
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[++cnt] = i;
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            vis[i*pr[j]] = true;
            if(i % pr[j] == 0) break;
        }
    }
}
ll ans;
int lst[N];
void work(int id,int x){
    for(int i=1;i<=cnt&&pr[i]*pr[i]<=x;i++){
        if(x % pr[i] == 0){
            ans += 1ll*(id-lst[pr[i]])*(n-id+1);
            while(x % pr[i] == 0) x /= pr[i];
            lst[pr[i]] = id;
        }
    }
    if(x > 1) ans += 1ll*(id-lst[x])*(n-id+1);
    lst[x] = id;
}
int main(){
    init();
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) work(i,a[i]);
    cout << ans;
	return 0;
}