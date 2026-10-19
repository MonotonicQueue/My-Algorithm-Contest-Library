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
int n,m;
vector<tuple<ll,ll,int>> a;
vector<int> v[N];
int main(){
    // freopen("print.in","r",stdin);
    // freopen("print.out","w",stdout);
    n = read(); m = read();
    for(int i=1;i<=n;i++){
        ll s = read(),t = read();
        a.emplace_back(t,s,i);
    }
    sort(a.begin(),a.end());
    priority_queue<int,vector<int>,greater<int> > q1;
    priority_queue<pli,vector<pli>,greater<pli> > q2;
    for(int i=1;i<=m;i++) q1.push(i);
    for(auto [t,s,i] : a){
        while(!q2.empty() && q2.top().fi <= t){
            q1.push(q2.top().se);
            q2.pop();
        }
        if(!q1.empty()){
            int x = q1.top(); q1.pop();
            v[x].push_back(i);
            q2.push(mk(t+s,x));
        }else{
            int x = q2.top().se;
            ll ti = q2.top().fi; q2.pop();
            v[x].push_back(i);
            q2.push(mk(ti+s,x));
        }
    }
    for(int i=1;i<=m;i++){
        cout << v[i].size() << " ";
        sort(v[i].begin(),v[i].end());
        for(int x : v[i]) cout << x << " ";
        cout << "\n";
    }
	return 0;
}