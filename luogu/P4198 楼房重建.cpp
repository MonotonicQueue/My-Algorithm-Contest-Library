#include<bits/stdc++.h>
#define ll __int128
#define LL long long
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
int n,m;
double mx[N<<2];
int t[N<<2];
#define ls rt<<1
#define rs rt<<1|1
int query(int rt,int l,int r,double d){
    if(mx[rt] <= d) return 0;
    if(l == r) return 1;
    int mid = (l+r) >> 1;
    if(mx[ls] > d) return query(ls,l,mid,d)+t[rt]-t[ls];
    return query(rs,mid+1,r,d);
}
void update(int rt,int l,int r,int pos,double d){
    if(l == r){
        t[rt] = 1;
        mx[rt] = d;
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(ls,l,mid,pos,d);
    else           update(rs,mid+1,r,pos,d);
    mx[rt] = max(mx[ls],mx[rs]);
    t[rt] = t[ls]+query(rs,mid+1,r,mx[ls]);
}
int main(){
    n = read(); m = read();
    while(m--){
        int x = read(),y = read();
        update(1,1,n,x,1.0*y/x);
        cout << t[1] << "\n";
    }
	return 0;
}