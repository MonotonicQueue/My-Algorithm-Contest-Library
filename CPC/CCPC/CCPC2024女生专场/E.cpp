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
const int N = 2e5+10;
int n,fa[N];
vector<int> v[N];
int get(int x){
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++){
        int p = read();
        v[i].clear();
        fa[i] = i;
        while(p--){
            int x = read();
            v[i].push_back(x);
        }
    }
    for(int i=n;i;i--){
        for(int y : v[i]){
            int t = get(y);
            fa[t] = i;
            cout << i << " " << t << "\n";
        }
    }
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
}