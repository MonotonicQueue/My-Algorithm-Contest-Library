#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const int N = 5e5+10;
int n,a[N]; 
ll c[N],f[N],s[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) c[i] = read(),s[i] = s[i-1]+c[i];
    for(int i=1;i<=n;i++) a[i] = read();
    deque<int> q;
    for(int i=1;i<=n;i++){
        f[i] = -1e18;
        while(!q.empty() && a[q.back()] < a[i]){
            f[i] = max(f[i],f[q.back()]+s[i-1]-s[q.back()-1]);
            q.pop_back();
        }
        if(q.empty()) f[i] = max(f[i],s[i-1]);
        else f[i] = max(f[i],f[q.back()]+s[i-1]-s[q.back()]);
        q.push_back(i);
    }
    ll ans = -1e18;
    for(int i=1;i<=n;i++) ans = max(ans,f[i]);
    cout << ans;
	return 0;
}
