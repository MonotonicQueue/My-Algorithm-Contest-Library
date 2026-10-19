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
int n;
struct node{int lx,rx,ly,ry;}a[N];
node operator+(node x,node y){
    return node{min(x.lx,y.lx),max(x.rx,y.rx),min(x.ly,y.ly),max(x.ry,y.ry)};
}
bool cmp1(node x,node y){
    if(x.lx != y.lx) return x.lx < y.lx;
    if(x.rx != y.rx) return x.rx < y.rx;
    if(x.ly != y.ry) return x.ly < y.ly;
    return x.ry < y.ry;
}
bool cmp2(node x,node y){
    return x.rx < y.rx;
}
int tmp[N],tot;
inline void lsh(){
    for(int i=1;i<=n;i++)
        tmp[++tot] = a[i].ly,
        tmp[++tot] = a[i].ry;
    sort(tmp+1,tmp+1+tot);
    tot = unique(tmp+1,tmp+1+tot)-tmp-1;
    for(int i=1;i<=n;i++)
        a[i].ly = lower_bound(tmp+1,tmp+1+tot,a[i].ly)-tmp,
        a[i].ry = lower_bound(tmp+1,tmp+1+tot,a[i].ry)-tmp;
}
vector<int> v1[N<<2],v2[N<<2];
bool vis[N];
#define ls rt<<1
#define rs rt<<1|1
void update(int rt,int l,int r,int ql,int qr,int id){
    v2[rt].push_back(id);
    if(ql <= l && r <= qr){
        v1[rt].push_back(id);
        return ;
    }
    int mid = (l+r)>>1;
    if(ql <= mid) update(ls,l,mid,ql,qr,id);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,id);
}
bool merge(int rt,int l,int r,int ql,int qr,int pos){
//    cout << rt << " " << l << " " << r << " " << ql << " " << qr << " " << pos << "\n";
    bool flag = false;
    for(int i=v1[rt].size()-1;~i;i--){
        if(vis[v1[rt][i]]){
            v1[rt].pop_back();
            continue;
        }
        int x = v1[rt][i];
        if(a[x].rx < a[pos].lx || a[x].lx > a[pos].rx) break;
        flag = true;
        a[pos] = a[pos]+a[x];
//        cout << pos << " " << x << "\n";
        vis[x] = true;
        v1[rt].pop_back();
    }
    if(ql <= l && r <= qr){
        for(int i=v2[rt].size()-1;~i;i--){
            if(vis[v2[rt][i]]){
                v2[rt].pop_back();
                continue;
            }
            int x = v2[rt][i];
            if(a[x].rx < a[pos].lx || a[x].lx > a[pos].rx) break;
            flag = true;
            a[pos] = a[pos]+a[x];
//            cout << pos << " " << x << "\n";
            vis[x] = true;
            v2[rt].pop_back();
        }
        return flag;
    }
    int mid = (l+r)>>1;
    if(ql <= mid) flag |= merge(ls,l,mid,ql,qr,pos);
    if(qr >  mid) flag |= merge(rs,mid+1,r,ql,qr,pos);
    return flag;
}
vector<node> ans;
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        a[i].lx = read(); a[i].rx = read();
        a[i].ly = read(); a[i].ry = read();
        a[i].lx++; a[i].ly++;
    }
    lsh();
    sort(a+1,a+1+n,cmp2);
//    for(int i=1;i<=n;i++) cout << a[i].ly << " " << a[i].ry << "\n"; 
    for(int i=1;i<=n;i++){
        while(merge(1,1,tot,a[i].ly,a[i].ry,i));
        update(1,1,tot,a[i].ly,a[i].ry,i);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) ans.push_back(a[i]);
    sort(ans.begin(),ans.end(),cmp1);
    cout << ans.size() << "\n";
    for(node x : ans) printf("%d %d %d %d\n",x.lx-1,x.rx,tmp[x.ly]-1,tmp[x.ry]);
	return 0;
}
