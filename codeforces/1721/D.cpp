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
int n,a[N],b[N];
bool chk(pair<vector<int>,vector<int>> &v,int c){
    vector<int> &v1 = v.fi,&v2 = v.se;
    int cnt0 = 0,cnt1 = 0;
    for(int x : v1) cnt0 += (a[x] >> c) & 1;
    for(int x : v2) cnt1 += (b[x] >> c) & 1;
    return cnt0+cnt1 == v1.size();
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) b[i] = read();
    vector<pair<vector<int>,vector<int>>> v;
    {
        vector<int> v1,v2;
        for(int i=1;i<=n;i++){
            v1.push_back(i);
            v2.push_back(i);
        }
        v.push_back(mk(v1,v2));
    }
    int ans = 0;
    for(int i=29;~i;i--){
        bool flag = true;
        for(auto &it : v){
            if(!chk(it,i)){
                flag = false;
                break;
            }
        }
        if(flag){
            ans |= 1<<i;
            vector<pair<vector<int>,vector<int>>> now;
            for(auto &it : v){
                pair<vector<int>,vector<int>> v1,v2;
                for(int x : it.fi)
                    if((a[x] >> i) & 1) v1.fi.push_back(x);
                    else v2.fi.push_back(x);
                for(int x : it.se)
                    if((b[x] >> i) & 1) v2.se.push_back(x);
                    else v1.se.push_back(x);
                if(!v1.fi.empty()) now.push_back(v1);
                if(!v2.fi.empty()) now.push_back(v2);
            }
            v = now;
        }
    }
    cout << ans << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}