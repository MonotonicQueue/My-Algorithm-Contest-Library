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
int n;
vector<pii> ans;
int main(){
    n = read();
    int x = 0,y = 0;
    ans.push_back(mk(0,-2)); ans.push_back(mk(0,-1)); ans.push_back(mk(0,0));
    ans.push_back(mk(1,-2)); ans.push_back(mk(1,0));
    ans.push_back(mk(2,-2)); ans.push_back(mk(2,-1)); ans.push_back(mk(2,0));
    for(int i=1;i<=n;i++){
        ans.push_back(mk(x,y+1)); ans.push_back(mk(x,y+2));
        ans.push_back(mk(x-1,y)); ans.push_back(mk(x-1,y+2));
        ans.push_back(mk(x-2,y)); ans.push_back(mk(x-2,y+1)); ans.push_back(mk(x-2,y+2));
        x -= 2; y += 2;
    }
    cout << ans.size() << "\n";
    for(auto it : ans) cout << it.fi << " " << it.se << "\n";
    return 0;
}