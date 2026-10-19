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
const int N = 1e5+10;
int n,m;
map<pii,set<int>>mp;
struct node{int u,v,w;};
vector<node> a;
int main(){
    n = read(); m = read();
    for(int i=1;i<=m;i++){
        int u = read(),v = read(),w = read();
        a.push_back(node{u,v,w});
        mp[mk(u,v)].insert(w);
    }
    int ans = 0;
    for(auto &[u,v,w]: a){
        set<int> *s[3] = {&mp[mk(u,v)],&mp[mk(u,w)],&mp[mk(v,w)]};
        int pos = 0;
        if(s[1]->size() < s[pos]->size()) pos = 1;
        if(s[2]->size() < s[pos]->size()) pos = 2;
        for(int x : *s[pos])
            if(s[0]->find(x) != s[0]->end() && s[1]->find(x) != s[1]->end() && s[2]->find(x) != s[2]->end()) ans++;
    }
    cout << ans;
    return 0;
}