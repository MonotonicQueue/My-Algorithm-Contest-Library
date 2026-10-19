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
const int N = 2e6+10;
int n,m,a[N],tot;
ll b[N];
struct node{
    int op,x,y;
}q[N];
struct BIT{
    ll t[N];
    inline void add(int x,int y){
        while(x <= tot){
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
}T1,T2;
int main(){
    n = read(); m = read();
    tot = 1; b[1] = 0;
    for(int i=1;i<=m;i++){
        char op; cin >> op;
        int x = read(),y = read();
        q[i] = node{op == 'Z',x,y};
        b[++tot] = q[i].y;
    }
    sort(b+1,b+1+tot);
    tot = unique(b+1,b+1+tot)-b-1;
    for(int i=1;i<=n;i++) a[i] = lower_bound(b+1,b+1+tot,a[i])-b;
    for(int i=1;i<=m;i++) q[i].y = lower_bound(b+1,b+1+tot,q[i].y)-b;
    for(int i=1;i<=n;i++) T1.add(a[i],1),T2.add(a[i],b[a[i]]);
    for(int i=1;i<=m;i++){
        int x = q[i].x,y = q[i].y;
        if(!q[i].op){
            T1.add(a[x],-1); T2.add(a[x],-b[a[x]]);
            a[x] = y;
            T1.add(a[x],1); T2.add(a[x],b[a[x]]);
        }else{
            ll res = T2.ask(y),sum = n-T1.ask(y);
            // cout << res << " " << sum << "\n";
            if(res+sum*b[y] >= x*b[y]) puts("TAK");
            else                 puts("NIE");
        }
    }
	return 0;
}
