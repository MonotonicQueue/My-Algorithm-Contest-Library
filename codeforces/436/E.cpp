#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int N = 6e5+10;
int n,w,a[N],b[N];
priority_queue<pli,vector<pli>,greater<pli>> q1,q2,q3,q4,q5;
int vis[N];
int main(){
    n = read(); w = read();
    for(int i=1;i<=n;i++) a[i] = read(),b[i] = read();
    for(int i=1;i<=n;i++) q1.push(mk(a[i],i)),q4.push(mk(b[i],i));
    ll ans = 0;
    while(w--){
        while(!q1.empty() && vis[q1.top().se] != 0) q1.pop();
        while(!q2.empty() && vis[q2.top().se] != 1) q2.pop();
        while(!q3.empty() && vis[q3.top().se] != 1) q3.pop();
        while(!q4.empty() && vis[q4.top().se] != 0) q4.pop();
        while(!q5.empty() && vis[q5.top().se] != 2) q5.pop();
        ll mn = 1e18; int type = 0;
        if(!q1.empty() && mn > q1.top().fi) mn = q1.top().fi,type = 1;
        if(!q2.empty() && mn > q2.top().fi) mn = q2.top().fi,type = 2;
        if(!q3.empty() && !q4.empty() && mn > q3.top().fi+q4.top().fi) mn = q3.top().fi+q4.top().fi,type = 3;
        if(!q5.empty() && !q4.empty() && mn > q5.top().fi+q4.top().fi) mn = q5.top().fi+q4.top().fi,type = 4;
        ans += mn;
        if(type == 1){
            int x = q1.top().se;
            vis[x] = 1; q1.pop();
            q2.push(mk(b[x]-a[x],x)); q3.push(mk(-a[x],x));
        }else if(type == 2){
            int x = q2.top().se; q2.pop();
            vis[x] = 2; q5.push(mk(-b[x]+a[x],x));
        }else if(type == 3){
            int x = q3.top().se,y = q4.top().se;
            q3.pop(); q4.pop();
            vis[x] = 0; vis[y] = 2;
            q1.push(mk(a[x],x)); q4.push(mk(b[x],x));
            q5.push(mk(-b[y]+a[y],y));
        }else{
            int x = q5.top().se,y = q4.top().se;
            q5.pop(); q4.pop();
            vis[x] = 1; vis[y] = 2;
            q2.push(mk(b[x]-a[x],x)); q3.push(mk(-a[x],x));
            q5.push(mk(-b[y]+a[y],y));
        }
    }
    cout << ans << "\n";
    for(int i=1;i<=n;i++) printf("%d",vis[i]);
    return 0;
}