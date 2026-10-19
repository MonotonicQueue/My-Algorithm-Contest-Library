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
int n;
struct node{
    char c;
    int x;
}a[N];
map<char,char> mp[1111];
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        cin >> a[i].c >> a[i].x;
    mp['N']['E'] = 'R'; mp['N']['W'] = 'L';
    mp['S']['E'] = 'L'; mp['S']['W'] = 'R';
    mp['E']['N'] = 'L'; mp['E']['S'] = 'R';
    mp['W']['N'] = 'R'; mp['W']['S'] = 'L';
    vector<pair<char,int> > v;
    char now = a[1].c;
    v.push_back(mk('Z',a[1].x));
    for(int i=2;i<=n;i++){
        v.push_back(mk(mp[now][a[i].c],0));
        v.push_back(mk('Z',a[i].x));
        now = a[i].c;
    }
    cout << v.size() << " " << a[1].c << "\n";
    for(auto it : v){
        if(it.fi == 'Z') cout << it.fi << " " << it.se << "\n";
        else cout << it.fi << "\n";
    }
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
