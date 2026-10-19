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
const int N = 5e5+10;
int n,a[N],p[N],tot,now;
int stk[N],top;
unordered_map<int,int> t[N];
double st = clock();
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    now = ++tot;
    ll ans = 0;
    a[n+1] = 1e9+1;
    for(int i=1;i<=n+1;i++){
        while(top && a[stk[top]] < a[i]){
            int x = stk[top],k = p[x];
            if(t[k].size() < t[now].size()) swap(k,now);
            for(auto &[val,cnt] : t[now]) 
                if(t[k].count(a[x]-val)) ans += 1ll*cnt*t[k][a[x]-val];
            for(auto &[val,cnt] : t[now]) t[k][val] += cnt;
            now = k;
            top--;
        }
        stk[++top] = i;
        p[i] = now;
        now = ++tot;
        t[now][a[i]] = 1;
    }
    cout << ans;
	return 0;
}