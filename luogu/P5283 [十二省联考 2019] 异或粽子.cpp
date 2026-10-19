#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
int n,K;
int t[N*32][2],sz[N*32],cnt=1;
ll a[N];
void insert(ll x){
    int p = 1;
    for(int i=31;~i;i--){
        int c = (x >> i) & 1;
        if(!t[p][c]) t[p][c] = ++cnt;
        p = t[p][c]; sz[p]++;
    }
}
struct node{
    ll x,k,i;
};
bool operator<(node x,node y){
    return x.x < y.x;
}
priority_queue<node> q;
ll ask(ll x,int k){
    int p = 1; ll res = 0;
    for(int i=31;~i;i--){
        int c = (x >> i) & 1;
        if(sz[t[p][c^1]] >= k){
            p = t[p][c^1];
            res |= (1ll << i);
        }else{
            k -= sz[t[p][c^1]];
            p = t[p][c];
        }
    }
    return res;
}
int main(){
    n = read(); K = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) a[i] ^= a[i-1];
    for(int i=0;i<=n;i++) insert(a[i]);
    for(int i=0;i<=n;i++) q.push(node{ask(a[i],1),1,i});
    K = K*2;
    ll ans = 0;
    while(K--){
        ll x = q.top().x,k = q.top().k,i = q.top().i; q.pop();
        if(K & 1) ans += x;
        q.push(node{ask(a[i],k+1),k+1,i});
    }
    cout << ans;
	return 0;
}
