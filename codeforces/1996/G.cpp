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
int n,m;
int mn[N<<2],sum[N<<2],tag[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    if(mn[ls] < mn[rs]){
        mn[rt] = mn[ls];
        sum[rt] = sum[ls];
    }else if(mn[ls] > mn[rs]){
        mn[rt] = mn[rs];
        sum[rt] = sum[rs];
    }else mn[rt] = mn[ls],sum[rt] = sum[ls]+sum[rs];
}
void build(int rt,int l,int r){
    tag[rt] = 0;
    if(l == r){
        mn[rt] = 0; sum[rt] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(rt);
}
inline void push_down(int rt){
    if(tag[rt]){
        mn[ls] += tag[rt];
        tag[ls] += tag[rt];
        mn[rs] += tag[rt];
        tag[rs] += tag[rt];
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,int d){
    if(ql > qr) return ;
    // if(rt == 1)cout <<"? "<< ql << " " << qr << " " <<d << "\n";
    if(ql <= l && r <= qr){
        mn[rt] += d;
        tag[rt] += d;
        return ;
    }
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
int query_sum(int rt,int l,int r,int ql,int qr,int d){
    if(ql <= l && r <= qr) return sum[rt];
    push_down(rt);
    int mid = (l+r) >> 1,res = 0;
    if(ql <= mid) res += query_sum(ls,l,mid,ql,qr,d);
    if(qr >  mid) res += query_sum(rs,mid+1,r,ql,qr,d);
    return res;
}
vector<int> v[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        build(1,1,n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=m;i++){
            int l = read(),r = read();
            if(l > r) swap(l,r);
            if(l == r) continue;
            v[l].push_back(r);
            v[r].push_back(l);
            update(1,1,n,l,r-1,1);
        }
        int ans = n-query_sum(1,1,n,1,n,0);
        // cout << n-query_sum(1,1,n,1,n,0) << "\n";
        for(int i=1;i<=n;i++){
            for(int x : v[i]){
                if(x < i) update(1,1,n,i,n,-1),update(1,1,n,1,x-1,-1),update(1,1,n,x,i-1,1);
                else update(1,1,n,x,n,1),update(1,1,n,1,i-1,1),update(1,1,n,i,x-1,-1);
            }
            // cout << i << " " << n-query_sum(1,1,n,1,n,0) << " " << mn[1] << "\n";
            ans = min(ans,n-query_sum(1,1,n,1,n,0));
        }
        cout << ans << "\n";
    }
	return 0;
}
/*
1
10 4
3 8
5 10
2 10
4 10
*/