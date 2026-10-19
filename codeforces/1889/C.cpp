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
const int M = 3;
int n,m,k,cnt[N];
vector<int> er[N],v[N];
int f[M][N],Lg[N];
struct ST_Table{
    int st[N][20];
    void insert(int x,int d){
        st[x][0] = d;
        for(int j=1;x-(1<<j)+1>=0;j++)
            st[x][j] = max(st[x][j-1],st[x-(1<<(j-1))][j-1]);
    }
    int query(int l,int r){
        if(l > r) return -1e9;
        int t = Lg[r-l+1];
        return max(st[r][t],st[l+(1<<t)-1][t]);
    }
}st[M];
void solve(){
    n = read(); m = read(); k = read();
    auto clear = [](){
        for(int i=1;i<=n;i++){
            cnt[i] = 0;
            er[i].clear(); v[i].clear();
        }
    };
    clear();
    multiset<int> s;
    for(int i=1;i<=m;i++){
        int l = read(),r = read();
        cnt[l]++; er[r+1].push_back(l);
    }
    for(int i=1;i<=n;i++){
        while(cnt[i]--) s.insert(i);
        for(int x : er[i]) s.erase(s.find(x));
        if(s.size() > k) v[i].push_back(-1);
        else{
            for(int x : s) v[i].push_back(x);
            v[i].push_back(i);
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++)
        if(v[i].size() == 1 && v[i].back() != -1) f[0][i] = ++sum;
        else f[0][i] = 0;
    for(int i=1;i<=n;i++) st[0].insert(i,f[0][i]);
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            f[j][i] = 0;
            if(v[i].size() == 1 && v[i].back() == -1){
                st[j].insert(i,f[j][i]);
                continue;
            }
            int now = v[i].size()-1,lst = 0;
            if(now <= j)
                for(int x : v[i]){
                    f[j][i] = max(f[j][i],st[j-now].query(lst,x-1)+1);
                    lst = x; now--;
                }
            st[j].insert(i,f[j][i]);
        }
    }
    cout << st[k].query(0,n) << "\n";
}
int main(){
    for(int i=2;i<=200001;i++) Lg[i] = Lg[i>>1]+1;
    int T = read();
    while(T--) solve();
	return 0;
}