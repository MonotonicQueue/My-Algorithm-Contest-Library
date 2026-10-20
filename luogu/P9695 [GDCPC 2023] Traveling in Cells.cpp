#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second 
#define mk make_pair
#define pii pair<ll,ll>
#define ull unsigned ll
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(ch != '-' && !isdigit(ch)) ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 3e5+10;
int n,Q;
int c[N],v[N];
struct BIT{
    ll t[N];
    void add(int x,ll y){
        while(x <= n){
            t[x] += y;
            x += x&(-x);
        }
    }
    ll ask(int x){
        ll res = 0;
        while(x){
            res += t[x];
            x -= x&(-x);
        }
        return res;
    }
    void clear(){
        for(int i=1;i<=n;i++) t[i] = 0;
    }
}T;
struct Segment{
    int ls,rs;
    int sum;
}t[N*50];
int tot,root[N];
void update(int &rt,int l,int r,int pos,int d){
    if(!rt){
        rt = ++tot;
        t[tot] = Segment{0,0,0};
    }
    t[rt].sum += d;
    if(l == r) return ;
    int mid = (l+r) >> 1;
    if(pos <= mid) update(t[rt].ls,l,mid,pos,d);
    else           update(t[rt].rs,mid+1,r,pos,d);
}
int query(int rt,int l,int r,int ql,int qr){
    if(!rt) return 0;
    if(ql <= l && r <= qr) return t[rt].sum;
    int mid = (l+r) >> 1,res = 0;
    if(ql <= mid) res += query(t[rt].ls,l,mid,ql,qr);
    if(qr >  mid) res += query(t[rt].rs,mid+1,r,ql,qr);
    return res;
}
// int query(vector<int> &v,int l,int r,int ql,int qr){
//     if(ql <= l && r <= qr){
//         ll res = 0;
//         for(int x : v) res += t[x].sum;
//         return res;
//     }
//     int mid = (l+r) >> 1,res = 0;
//     if(ql <= mid){
//         vector<int> lc;
//         for(int x : v)
//             if(t[x].ls) lc.push_back(t[x].ls);
//         res += query(lc,l,mid,ql,qr);
//     }
//     if(qr >  mid){
//     	vector<int> rc;
//     	for(int x : v)
//             if(t[x].rs) rc.push_back(t[x].rs);
//         res += query(rc,mid+1,r,ql,qr);
// 	}
// 	return res;
// }
void solve(){
    n = read(); Q = read();
    T.clear(); tot = 0;
    for(int i=1;i<=n;i++) root[i] = 0;
    for(int i=1;i<=n;i++) c[i] = read();
    for(int i=1;i<=n;i++) v[i] = read();
    for(int i=1;i<=n;i++) T.add(i,v[i]);
    for(int i=1;i<=n;i++){
        update(root[c[i]],1,n,i,1);
    }
    while(Q--){
		int op = read();
		if(op == 1){
			int p = read(),x = read();
			update(root[c[p]],1,n,p,-1);
			c[p] = x;
			update(root[c[p]],1,n,p,1);
		}else if(op == 2){
			int p = read(),x = read();
			T.add(p,-v[p]);
			v[p] = x;
			T.add(p,v[p]);
		}else{
			int x = read(),k = read();
			vector<int> V;
			for(int i=1;i<=k;i++){
				int c = read();
				V.push_back(root[c]);
			}
			int L = x,R = x;
			int l = x,r = n;
			while(l <= r){
				int mid = (l+r) >> 1;
                int cnt = 0;
                for(int rt : V) cnt += query(rt,1,n,x,mid);
				if(cnt == mid-x+1) R = mid,l = mid+1;
				else r = mid-1; 
			}
			l = 1,r = x;
			while(l <= r){
				int mid = (l+r) >> 1;
                int cnt = 0;
                for(int rt : V) cnt += query(rt,1,n,mid,x);
				if(cnt == x-mid+1) L = mid,r = mid-1;
				else l = mid+1; 
			}
			cout << T.ask(R)-T.ask(L-1) << "\n";
		}
    }
}
int main(){
    int TTT = read();
    while(TTT--) solve();
    return 0;
}
/*
2
5 10
1 2 3 1 2
1 10 100 1000 10000
3 3 1 3
3 3 2 2 3
2 5 20000
2 3 200
3 3 2 1 3
3 3 3 1 2 3
1 3 4
2 1 100000
1 2 2
3 1 2 1 2
4 1
1 2 3 4
1000000 1000000 1000000 1000000
3 4 4 1 2 3 4
*/
