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
const int N = 4e5+10;
int n,m,a[N],pos[N],match[N];
int tmp[N],tot;
struct Matrix{
    bool mat[2][2];
    Matrix(){
        memset(mat,0,sizeof(mat));
    }
    Matrix operator*(const Matrix x)const{
        Matrix res;
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++) res.mat[i][j] |= mat[i][k]&x.mat[k][j];
        return res;
    }
}t[N<<2];
struct node{int k,x,y;};
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    t[rt] = t[ls]*t[rs];
}
void build(int rt,int l,int r){
    memset(t[rt].mat,0,sizeof(t[rt].mat));
    if(l == r) return ;
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void update(int rt,int l,int r,node x,bool d){
    if(l == r){
        t[rt].mat[x.x][x.y] = d;
        return ;
    }
    int mid = (l+r) >> 1;
    if(x.k <= mid) update(ls,l,mid,x,d);
    else update(rs,mid+1,r,x,d);
    push_up(rt);
}
bool chk(){
    return t[1].mat[0][0] | t[1].mat[1][1];
}
vector<node> v[N];
void solve1(){
    if(n == 1){
        cout << "0\n";
        return ;
    }
    
    for(int i=1,j=1;i<=2*n;i++){
        pos[j] = i;
        if(i & 1) j++;
        else if(j > n) j -= n;
        else j += n;
    }
    // for(int i=1;i<=2*n;i++) cout << pos[i] << " ";
    // cout << "\n";
    tot = 0;
    for(int i=1;i<=n;i++){
        tmp[++tot] = a[2*i-1]+a[2*i];
        tmp[++tot] = a[2*i-1]+a[match[2*i]];
        tmp[++tot] = a[match[2*i-1]]+a[2*i];
        tmp[++tot] = a[match[2*i-1]]+a[match[2*i]];
    }
    sort(tmp+1,tmp+1+tot);
    tot = unique(tmp+1,tmp+1+tot)-tmp-1;
    for(int i=1;i<=tot;i++) v[i].clear();
    for(int k=1;k<=n;k++){
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++){
                int s = 0;
                s += i ? a[match[2*k-1]] : a[2*k-1];
                s += j ? a[match[2*k]] : a[2*k];
                int id = lower_bound(tmp+1,tmp+1+tot,s)-tmp;
                v[id].push_back(node{pos[2*k]/2,i,j});
            }
    }
    build(1,1,n);
    int ans = 2e9;
    for(int l=1,r=0;l<=tot;l++){
        while(!chk() && r < tot){
            ++r;
            for(node x : v[r]) update(1,1,n,x,1);
        }
        if(chk()) ans = min(ans,tmp[r]-tmp[l]);
        for(node x : v[l]) update(1,1,n,x,0);
    }
    cout << ans << "\n";
}
void solve2(){
    int mx = 0,mn = 2e9;
    for(int i=1;i<=n/2;i++){
        int p1 = a[2*i-1]+a[2*i],p2 = a[match[2*i-1]]+a[match[2*i]],
            q1 = a[match[2*i-1]]+a[2*i],q2 = a[2*i-1]+a[match[2*i]];
            if(abs(p1-p2) < abs(q1-q2)){
                mx = max(mx,max(p1,p2));
                mn = min(mn,min(p1,p2));
            }else{
                mx = max(mx,max(q1,q2));
                mn = min(mn,min(q1,q2));
            }
    }
    printf("%d\n",mx-mn);
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=2*n;i++) a[i] = read();
        for(int i=1;i<=n;i++){
            match[i] = i+n;
            match[i+n] = i;
        }
        if(n & 1) solve1();
        else solve2();
    }
	return 0;
}
/*
1
5
5 4 6 4 1 7 6 9 3 7
*/