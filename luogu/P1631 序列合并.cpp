#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
const int N = 1e5+10;
int n,a[N],b[N];
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    typedef tuple<int,int,int> info;
    priority_queue<info,vector<info>,greater<info>> q;
    for(int i=1;i<=n;i++)
        q.push(make_tuple(a[i]+b[1],i,1));
    int k = n;
    while(k--){
        auto [w,u,v] = q.top(); q.pop();
        cout << w << " ";
        if(v < n) q.push(make_tuple(a[u]+b[v+1],u,v+1));
    }
    return 0;
}