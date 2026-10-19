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
const int N = 1e5+10;
ull P = 131;
struct Segment{
    int n,a[N],len[N<<2],mx[N<<2];
    ull hsh[N<<2],pw[N];
    #define ls rt<<1
    #define rs rt<<1|1
    pair<ull,int> query(int rt,int l,int r,int d){
        if(mx[rt] < d) return mk(0ull,0);
        if(l == r) return mk(a[l],1);
        int mid = (l+r) >> 1;
        if(mx[rs] >= d){
            auto res = query(rs,mid+1,r,d);
            int x = len[rt]-len[rs];
            return mk(hsh[rt]-hsh[rs]*pw[x]+res.fi*pw[x],res.se+x);
        }else return query(ls,l,mid,d);
    }
    void update(int rt,int l,int r,int pos){
        if(l == r){
            hsh[rt] = mx[rt] = a[pos];
            len[rt] = 1;
            return ;
        }
        int mid = (l+r) >> 1;
        if(pos <= mid) update(ls,l,mid,pos);
        else           update(rs,mid+1,r,pos);
        mx[rt] = max(mx[ls],mx[rs]);
        auto res = query(ls,l,mid,mx[rs]);
        hsh[rt] = res.fi+hsh[rs]*pw[res.se];
        len[rt] = res.se+len[rs];
    }
    void init(){
        n = read(); 
        for(int i=1;i<=n;i++) a[i] = read();
        pw[0] = 1;
        for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
        for(int i=n;i>=1;i--) update(1,1,n,i);
    }
    void change(int x,int y){
        a[x] = y;
        update(1,1,n,x);
    }
}T1,T2;
int main(){
    T1.init(); T2.init();
    int Q = read();
    while(Q--){
        int o = read(),x = read(),y = read();
        if(o == 1) T1.change(x,y);
        else       T2.change(x,y);
        // cout << T1.hsh[1] << "  " << T2.hsh[1] << "\n";
        puts(T1.hsh[1] == T2.hsh[1] ? "YES" : "NO");
    }
	return 0;
} 
/*
5
5 4 3 2 5
5
4 4 5 2 1
*/