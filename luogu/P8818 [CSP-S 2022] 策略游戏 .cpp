#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

ll read(){
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    ll X = 0 , f = 1;
    if(ch == '-') f = -1 , ch = getchar();
    while(isdigit(ch)) X = (X<<1)+(X<<3)+ch-'0' , ch = getchar();
    return X*f;
}

const int N = 1e5+11;
class Segment_Tree{
	public:
		struct SegmentTree{
		    int l,r;
		    int max1,max2,min1,min2;
		    SegmentTree(){
		    	max1 = max2 = -1e10;
		    	min1 = min2 =  1e10;
			}
		    #define ls(x) x<<1
		    #define rs(x) x<<1|1
		}t[N<<2];
		
		inline void push_up(int x){
		    t[x].max1 = max(t[ls(x)].max1,t[rs(x)].max1);
		    t[x].max2 = max(t[ls(x)].max2,t[rs(x)].max2);
		    t[x].min1 = min(t[ls(x)].min1,t[rs(x)].min1);
		    t[x].min2 = min(t[ls(x)].min2,t[rs(x)].min2);
		}
		
		void build(int p,int l,int r){
		    t[p].l = l; t[p].r = r;
		    if(l == r){
		        int c = read();
		        if(c >= 0) t[p].max1 = t[p].min1 = c;
		        if(c <= 0) t[p].max2 = t[p].min2 = c;
		        return;
		    }
		    int mid = (l+r)>>1;
		    build(ls(p),l,mid);
		    build(rs(p),mid+1,r);
		    push_up(p);
		}
		SegmentTree query(int p,int l,int r){
		    if(l <= t[p].l && r >= t[p].r) return t[p];
		    int mid = (t[p].l+t[p].r)>>1;
		    if(mid<l)return query(p<<1|1,l,r);
			else if(mid>=r)return query(p<<1,l,r);
			else{
				SegmentTree a,b;
				a=query(p<<1,l,r);
				b=query(p<<1|1,l,r);
				SegmentTree ttt;
				ttt.max1 = max(a.max1,b.max1);
		   		ttt.max2 = max(a.max2,b.max2);
		    	ttt.min1 = min(a.min1,b.min1);
		    	ttt.min2 = min(a.min2,b.min2);
				return ttt;
			}
		}
}a,b;

int n,m,q;

signed main(){
    n = read(); m = read(); q = read();
    a.build(1,1,n);
    b.build(1,1,m);
    while(q--){
    	int l1,r1,l2,r2;
    	l1 = read(); r1 = read();
    	l2 = read(); r2 = read();
    	Segment_Tree::SegmentTree x,y;
    	x = a.query(1,l1,r1);
    	y = b.query(1,l2,r2);
    	int ans = -1e19;
    	int minn = min(y.min1,y.min2) , maxn = max(y.max1,y.max2);
    	if(x.max1 != -1e10) ans = max(ans,x.max1*minn);
    	if(x.min1 !=  1e10) ans = max(ans,x.min1*minn);
    	if(x.max2 != -1e10) ans = max(ans,x.max2*maxn);
    	if(x.min2 !=  1e10) ans = max(ans,x.min2*maxn);
    	printf("%lld\n",ans);
	}
    return 0;
}