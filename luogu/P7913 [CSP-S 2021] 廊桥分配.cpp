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
struct Solve{
    int m,cnt[N],pos[N];
    vector<pii> v;
    set<int> s;
    void work(){
        for(int i=1;i<=m;i++){
            int a = read(),b = read();
            v.push_back(mk(a,i));
            v.push_back(mk(b,-i));
        }
        sort(v.begin(),v.end());
        for(int i=1;i<=n;i++) s.insert(i);
        for(auto it : v){
            if(it.se > 0){
                int i = it.se;
                if(s.empty()) continue;
                int x = *s.begin();
                s.erase(x);
                cnt[x]++; pos[i] = x;
            }else{
                int i = -it.se;
                if(pos[i]) s.insert(pos[i]);
            }
        }
        for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];
    }
}S[2];
signed main(){
    n = read();
    S[0].m = read(); S[1].m = read();
    S[0].work(); S[1].work();
    int ans = 0;
    for(int i=0;i<=n;i++){
        ans = max(ans,S[0].cnt[i]+S[1].cnt[n-i]);
    }
    cout << ans;
    return 0;
}
