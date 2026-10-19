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
const int N = 3e5+10;
int n,m;
int a[N],aa[N],c[N],Lg[N];
int mx[20][N],flag[N];
struct node{
    ll sum,x;
    bool d,tp;
}t[N<<2];
#define ls rt<<1
#define rs rt<<1|1

void build(int rt,int l,int r){
    if(l == r){
        t[rt].x = l;
        return ;
    }
    int mid = (l+r) >> 1,R = Lg[r-l+1];
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[rt].tp = 0;
    if(!t[rt].d){
        if(a[t[ls].x] >= R){
            t[rt].x = t[ls].x;
            flag[r]++; flag[mid]--;
            t[rt].tp = 1;
        }else t[rt].x = t[rs].x;
    }else{
        if(a[t[rs].x] >= R) t[rt].x = t[rs].x;
        else t[rt].x = t[ls].x;
    }
}
void getmx(int rt,int l,int r,int *mx){
    t[rt].sum = 1ll*(r-l+1)*(l+r)/2;
    if(l == r) return ;
    int mid = (l+r) >> 1,d = t[rt].d,k = Lg[r-l+1];
    if(~mx[rt]) mx[ls] = mx[rs] = mx[rt];
    else mx[rt<<1|d] = k;
    getmx(ls,l,mid,mx); getmx(rs,mid+1,r,mx);
}
ll ans[N];
bool vis[N];
void solve(int n){
    memset(flag,0,sizeof(flag));
    build(1,1,n);
    // for(int i=1;i<=n;i*=2){
    //     for(int j=i;j<2*i;j++) cout << t[j].x << " ";
    //     cout << "\n";
    // }
    // for(int i=1;i<=n;i++) cout << flag[i];
    // cout << "\n";
    ll sum = 0;
    auto add = [&](int x){
        if(vis[x]) return 0;
        vis[x] = true;
        return x;
    };
    for(int i=n,rt=1,s=0;i;i--){
        if((1 << Lg[i]) == i){
            sum = 0;
            if(i != n) rt <<= 1,s++;
            for(int j=1;j<=i;j++) vis[j] = 0;
            sum += add(t[rt].x);
        }
        ans[i] = sum;
        flag[i] += flag[i+1];
        if(flag[i]) continue;
        sum += add(i);
        int x = n+i-1;
        while(x != rt){
            int d = x & 1;
            if(!d){
                if(t[x>>1].tp) sum += t[x|1].sum;
                else break;
            }else{
                if(a[t[x^1].x] >= mx[s][x^1]) sum += add(t[x^1].x);
            }
            x >>= 1;
        }
    }
    ll res = 0;
    for(int i=1;i<=m;i++) res ^= 1ll*i*ans[c[i]];
    cout << res << "\n";
}
char ch[N];
signed main(){
    // freopen("arena5.in","r",stdin);
    // freopen("arena.out","w",stdout);
    n = read(); m = read();
    for(int i=1;i<=n;i++) aa[i] = read();
    for(int i=1;i<=m;i++) c[i] = read();
    int k = 1;
    while(k < n) k <<= 1;
    for(int i=2;i<=k;i++) Lg[i] = Lg[i>>1]+1;
    for(int i=k/2;i;i>>=1){
        scanf("%s",ch);
        for(int j=i;j<2*i;j++) t[j].d = ch[j-i]-'0';
    }
    
    memset(mx,-1,sizeof(mx));
    for(int s=0;(1<<s)<=k;s++)
        getmx(1<<s,1,k>>s,mx[s]);
    int T = read();
    while(T--){
        int X[4];
        for(int i=0;i<=3;i++) X[i] = read();
        for(int i=1;i<=n;i++) a[i] = aa[i]^X[i&3];
        solve(k);
    }
    return 0;
}
