#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 1<<20;
int n,mn[N],a[N],p[N],pos[N];
int fa[N];
int get(int x){
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}
int main(){
    n = read();
    for(int s=0;s<(1<<n);s++) mn[s] = a[s] = read();
    for(int s=0;s<(1<<n);s++) p[s] = pos[s] = s;
    for(int k=0;k<n;k++)
        for(int s=0;s<(1<<n);s++)
            if((s >> k) & 1){
                if(mn[s^(1<<k)] < mn[s])
                    mn[s] = mn[s^(1<<k)],pos[s] = pos[s^(1<<k)];
            }
    sort(p,p+(1<<n),[](int x,int y){return mn[x] < mn[y];});
    for(int i=1;i<(1<<n);i++) fa[i] = i;
    vector<pii> ans;
    ll val = 0;
    for(int i=0;i<(1<<n);i++){
        int s = p[i];
        for(int k=0;k<n;k++){
            if((s >> k) & 1) continue;
            int t = s | (1<<k);
            if(get(pos[s]) != get(t)){
                fa[get(pos[s])] = get(t);
                ans.emplace_back(pos[s],t);
                val += a[pos[s]];
            }
        }
            
    }
    cout << ans.size() << "\n";
    for(auto [u,v] : ans){
        cout << u << " " << v << "\n";
    }
    cout << val;
    return 0;
}

/**/