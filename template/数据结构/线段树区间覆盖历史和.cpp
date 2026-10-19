const int N = 1e5+10;
#define ll long long
namespace SGT{
	ll sum[N<<2],hsum[N<<2];
    /*
    sum 区间和
    hsum 区间历史和
    */
	struct Tag{
		ll tag,add0,addh;
        /*
        tag 最新要覆盖下去的标记
        add0 sum_x 对 hsum 的贡献的系数
        addh hsum 要加的标记
        */
		Tag(ll tag=0,ll add0=0,ll addh=0): 
		tag(tag),add0(add0),addh(addh){}
		bool operator!=(const Tag &o){
			return tag != o.tag || add0 != o.add0 || addh != o.addh;
		}
	}t[N<<2];
	#define ls rt<<1
	#define rs rt<<1|1
	inline void push_up(int rt){
		sum[rt] = sum[ls]+sum[rs];
		hsum[rt] = hsum[ls]+hsum[rs];
	}
	void build(int rt,int l,int r){
		sum[rt] = hsum[rt] = 0;
		t[rt] = Tag();
		if(l == r) return ;
		int mid = (l+r) >> 1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(rt);
	}
	inline void change(int rt,int l,int r,Tag d){
		hsum[rt] += d.addh*(r-l+1)+d.add0*sum[rt];
		t[rt].addh += d.addh;
		t[rt].add0 += d.add0;
		if(d.tag){
			t[rt].addh += t[rt].tag*t[rt].add0;
			t[rt].add0 = 0;
			sum[rt] = d.tag*(r-l+1);
			t[rt].tag = d.tag;
		}
	}
	inline void push_down(int rt,int l,int r){
		if(t[rt] != Tag(0,0,0)){
			int mid = (l+r) >> 1;
			change(ls,l,mid,t[rt]);
			change(rs,mid+1,r,t[rt]);
			t[rt] = Tag(0,0,0);
		}
	}
	void update(int rt,int l,int r,int ql,int qr,Tag d){
		if(ql > qr) return ;
		if(ql <= l && r <= qr) return change(rt,l,r,d);
		push_down(rt,l,r);
		int mid = (l+r) >> 1;
		if(ql <= mid) update(ls,l,mid,ql,qr,d);
		if(qr >  mid) update(rs,mid+1,r,ql,qr,d);
		push_up(rt);
	}
	ll query(int rt,int l,int r,int ql,int qr){
		if(ql <= l && r <= qr) return hsum[rt];
		push_down(rt,l,r);
		int mid = (l+r) >> 1; ll res = 0;
		if(ql <= mid) res += query(ls,l,mid,ql,qr);
		if(qr >  mid) res += query(rs,mid+1,r,ql,qr);
		return res;
	}
}