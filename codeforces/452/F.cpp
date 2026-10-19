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
int n,a[N];
ull hsh1[N<<2],hsh2[N<<2],pw[N],P=13131;
#define ls rt<<1
#define rs rt<<1|1
inline void push_up(int rt,int l,int r){
    int mid = (l+r)>>1;
    hsh1[rt] = hsh1[ls]*pw[r-mid]+hsh1[rs];
    hsh2[rt] = hsh2[rs]*pw[mid-l+1]+hsh2[ls];
}
void update(int rt,int l,int r,int pos){
    if(l == r){
        hsh1[rt] = hsh2[rt] = 1;
        return ;
    }
    int mid = (l+r)>>1;
    if(pos <= mid) update(ls,l,mid,pos);
    else           update(rs,mid+1,r,pos);
    push_up(rt,l,r);
}
ull res1,res2;
void query1(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        res1 = res1*pw[r-l+1]+hsh1[rt];
        return ;
   }
    int mid = (l+r)>>1;
    if(ql >  mid) return query1(rs,mid+1,r,ql,qr),void();
    if(qr <= mid) return query1(ls,l,mid,ql,qr),void();
    query1(ls,l,mid,ql,qr); query1(rs,mid+1,r,ql,qr);
}
void query2(int rt,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
        res2 = res2*pw[r-l+1]+hsh2[rt];
        return ;
    }
    int mid = (l+r)>>1;
    if(ql >  mid) return query2(rs,mid+1,r,ql,qr),void();
    if(qr <= mid) return query2(ls,l,mid,ql,qr),void();
    query2(rs,mid+1,r,ql,qr); query2(ls,l,mid,ql,qr); 
}
int main(){
    n = read();
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    for(int i=1;i<=n;i++) a[i] = read();   
    bool flag = false;
    for(int i=1;i<=n;i++){
        update(1,1,n,a[i]);
        int k = min(a[i]-1,n-a[i]);
        res1 = res2 = 0;
        query1(1,1,n,a[i]-k,a[i]+k);
        query2(1,1,n,a[i]-k,a[i]+k);
        if(res1 != res2) flag = true;
    }
    puts(flag ? "YES" : "NO");
	return 0;
}