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
const int N = 2100;
int n;
int ask(int l,int r){
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);
    return read();
}
int suf[N],sum[N],p[N];
vector<int> G[N];
void solve(){
    n = read();
    for(int i=n-1;i;i--){
        suf[i] = ask(i,n);
        for(int _=1;_<=suf[i]-suf[i+1];_++){
            int l = i+1,r = n,res = -1;
            while(l <= r){
                int mid = (l+r) >> 1;
                if(ask(i,mid) > sum[mid]) res = mid,r = mid-1;
                else l = mid+1;
            }
            for(int j=res;j<=n;j++) sum[j]++;
            assert(res != -1);
            G[i].push_back(res);
            G[res].push_back(i);
        }
    }
    int x = 0;
    for(int i=1;i<=n;i++)
        if(G[i].size() == 1){
            x = i;
            break;
        }
    int lst = 0;
    p[x] = 1;
    for(int i=2;i<=n;i++){
        int nxt = 0;
        for(int y : G[x]){
            if(y != lst) nxt = y;
        }
        lst = x;
        x = nxt;
        p[x] = i;
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << "\n";
}
int main(){
    int T = 1;
    while(T--) solve();
    return 0;
}
