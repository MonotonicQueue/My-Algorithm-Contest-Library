#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 5e5+10;
int n,m,a[N];
int mn[N];
ll f[N];
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i] = read();
        mn[i] = 0;
    }
    m = read();
    for(int i=1;i<=m;i++){
        int l = read(),r = read();
        mn[r] = max(mn[r],l);
    }
    deque<int> q;
    q.push_back(0);
    for(int i=1;i<=n;i++){
        f[i] = f[q.front()]+a[i];
        if(mn[i] != n+1)
            while(!q.empty() && q.front() < mn[i]) q.pop_front();
        while(!q.empty() && f[q.back()] >= f[i]) q.pop_back();
        q.push_back(i);
    }
    cout << f[q.front()] << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}