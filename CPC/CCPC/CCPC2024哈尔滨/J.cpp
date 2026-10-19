#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
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
const ll inf = 1e18;
int n,m;
ll a[N],b[N],x[N],t[N];
queue<ll> v[N];
void solve(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) b[i] = a[i] = read();
    for(int i=1;i<=n;i++)
        while(!v[i].empty()) v[i].pop();
    for(int i=1;i<=m;i++){
        x[i] = read(); t[i] = read();
        v[t[i]].push(x[i]);
    }
    priority_queue<pii>q;
    for(int i=1;i<=n;i++){
        if(v[i].empty()) q.push(mk(-inf,i));
        else q.push(mk(-v[i].front(),i));
    }
    ll lst = 0;
    for(int i=1;i<=m;i++){
        while(!q.empty()){
            int y = q.top().se; q.pop();
            if(x[i]-lst <= a[y]){
                a[y] -= x[i]-lst;
                lst = x[i];
                // v[y].pop();
                if(a[y]){
                    if(v[y].empty()) q.push(mk(-inf,y));
                    else q.push(mk(-v[y].front(),y));
                }
                break;
            }
            lst += a[y]; a[y] = 0;
        }
        if(lst != x[i]){
            cout << lst << "\n";
            for(int j=1;j<=n;j++) assert(a[j] == 0);
            return ;
        }
        if(a[t[i]]) q.pop();
        a[t[i]] = b[t[i]];
        
        v[t[i]].pop();
        if(v[t[i]].empty()) q.push(mk(-inf,t[i]));
        else q.push(mk(-v[t[i]].front(),t[i]));
    }
    for(int i=1;i<=n;i++) lst += a[i];
    cout << lst << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
