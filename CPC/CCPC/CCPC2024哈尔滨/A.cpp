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
const int N = 2e6+10;
int L,R,vis[N],Lg[N],cnt;
vector<pii> G[120];
int get(int x){
    if(vis[x]) return vis[x];
    if(!x) return vis[x] = ++cnt;
    vis[x] = ++cnt;
    int y = get(x-1);
    G[vis[x]].push_back(mk(y,0));
    G[vis[x]].push_back(mk(y,1));
    return vis[x];
}
int ask(int l,int r,int ql,int qr,bool flag=0){
    if(l == ql && r == qr) return get(Lg[r-l+1]);
    int mid = (l+r) >> 1;
    if(ql > mid){
        int x = ++cnt;
        int y = ask(mid+1,r,ql,qr,1);
        G[x].push_back(mk(y,1));
        return x;
    }
    if(qr <= mid){
        if(!flag) return ask(l,mid,ql,qr);
        int x = ++cnt;
        int y = ask(l,mid,ql,qr,1);
        G[x].push_back(mk(y,0));
        return x;
    }
    if(flag){
        int x = ++cnt;
        int L = ask(l,mid,ql,mid,1);
        int R = ask(mid+1,r,mid+1,qr,1);
        G[x].push_back(mk(L,0));
        G[x].push_back(mk(R,1));
        return x;
    }else{
        int L = ask(l,mid,ql,mid,0);
        int R = ask(mid+1,r,mid+1,qr,1);
        G[L].push_back(mk(R,1));
        return L;
    }
}
signed main(){
    for(int i=2;i<=1000000;i++) Lg[i] = Lg[i>>1]+1;
    L = read(); R = read();
    ask(0,(1<<20)-1,L,R);
    cout << cnt << "\n";
    for(int i=1;i<=cnt;i++){
        cout << G[i].size() << " ";
        for(auto it : G[i]) cout << it.fi << " " << it.se << " ";
        cout << "\n";
    }
    return 0;
}
