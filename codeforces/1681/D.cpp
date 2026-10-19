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
const int N = 110;
ll n,x;
int bfs(){
    queue<ll> q;
    map<ll,int> mp;
    q.push(x);
    mp[x] = 1;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        ll tmp = u,len = 0;
        vector<int> cnt(10,0);
        while(tmp) len++,cnt[tmp%10]++,tmp/=10;
        if(len == n) return mp[u]-1;
        for(int i=2;i<=9;i++){
            if(!cnt[i]) continue;
            if(!mp[u*i]) mp[u*i] = mp[u]+1,q.push(u*i);
        }
    }
    return -1;
}
void solve(){
    n = read(); x = read();
    cout << bfs() << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
