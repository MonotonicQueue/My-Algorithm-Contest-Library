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
const int N = 2e5+10;
int n,k,m;
ll t;
struct node{
    ll a,b;
}c[N];
bool vis[N];
int main(){
    n = read(); k = read(); t = read();
    for(int i=1;i<=n;i++)
        c[i].a = read(),c[i].b = read();
    sort(c+1,c+1+n,[](node x,node y){return x.b < y.b;});
    ll sum = 0;;
    for(int i=1;i<=n;i++)
        if(sum+c[i].b <= t) sum += c[i].b,m = i;
    if(m <= k){
        cout << m << "\n";
        return 0;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q1,q2,q3;
    for(int i=k+1;i<=n;i++){
        q2.push(mk(c[i].a,i));
        q3.push(mk(c[i].b,i));
    }
    sum = 0;
    for(int i=1;i<=k;i++){
        sum += c[i].b;
        q1.push(mk(c[i].a-c[i].b,i));
    }
    int ans = k;
    for(int i=k+1;i<=n;i++){
        while(vis[q2.top().se]) q2.pop();
        while(vis[q3.top().se]) q3.pop();
        ll c1 = q1.top().fi+q3.top().fi,c2 = q2.top().fi;
        if(sum+min(c1,c2) > t) break;
        sum += min(c1,c2); ans++;
        if(c1 < c2){
            int x = q3.top().se;
            vis[x] = 1;
            q1.pop(); q3.pop();
            q1.push(mk(c[x].a-c[x].b,x));
        }else{
            int x = q2.top().se;
            vis[x] = 1;
            q2.pop();
        }
    }
    cout << ans;
	return 0;
}
