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
const int N = 1010;
int n,a[N];
vector<int> v[N];
vector<pii> ans;
void solve(int l,int r){
    if(l == r) return ;
    int mid = (l+r) >> 1;
    vector<int> ve;
    for(int i=mid+1;i<=r;i++)
        for(int y : v[i]) ve.push_back(y);
    for(int y : ve)
        ans.push_back(mk(2,y));
    for(int i=l+1;i<=mid;i++) ans.push_back(mk(1,i));
    solve(mid+1,r); solve(l,mid);
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read(),v[a[i]].push_back(i);
    solve(0,n);
    cout << ans.size() << "\n";
    for(auto it : ans) cout << it.fi << " " << it.se << "\n";
	return 0;
} 
