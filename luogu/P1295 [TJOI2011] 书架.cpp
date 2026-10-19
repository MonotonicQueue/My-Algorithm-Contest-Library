#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,m;
ll f[N],a[N],sum[N];
struct Segment_Tree{
ll tag[N<<2],mn[N<<2];
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt){
    mn[rt] = min(mn[ls],mn[rs]);
}
inline void change(int rt,ll d){
    mn[rt] += d;
    tag[rt] += d;
}
inline void push_down(int rt){
    if(tag[rt]){
        change(ls,tag[rt]);
        change(rs,tag[rt]);
        tag[rt] = 0;
    }
}
void update(int rt,int l,int r,int ql,int qr,ll d){
    if(ql <= l && r <= qr) return change(rt,d);
    push_down(rt);
    int mid = (l+r) >> 1;
    if(ql <= mid) update(ls,l,mid,ql,qr,d);
    if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
    push_up(rt);
}
ll query(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr) return mn[rt];
    push_down(rt);
    int mid = (l+r) >> 1;
    if(qr <= mid) return query(ls,l,mid,ql,qr);
    if(ql >  mid) return query(rs,mid+1,r,ql,qr);
    return min(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
void update(int ql,int qr,ll d){
    update(1,1,n,ql,qr,d);
}
ll query(int ql,int qr){
    return query(1,1,n,ql,qr);
}
}T;
int stk[N],top;
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
    auto chk = [&](){
        for(int i=1;i<=n;i++)
            if(a[i] > m) return false;
        return true;
    };
    if(!chk()) return puts("-1"),0;
    for(int i=1,j=1;i<=n;i++){
        while(j <= n && sum[i]-sum[j-1] > m) j++;
        assert(j <= i);
        T.update(i,i,f[i-1]+a[i]);
        while(top && a[stk[top]] <= a[i]){
            T.update(stk[top-1]+1,stk[top],a[i]-a[stk[top]]);
            top--;
        }
        stk[++top] = i;
        f[i] = T.query(j,i);
    }
    cout << f[n];
	return 0;
}