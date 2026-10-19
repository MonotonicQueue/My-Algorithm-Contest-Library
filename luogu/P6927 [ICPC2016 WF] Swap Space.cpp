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
const int N = 1e6+10;
int n,tot1,tot2;
struct node{
    ll a,b;
}a[N],b[N];
bool cmp(node x,node y){
    return x.a < y.a;
}
bool cmp1(node x,node y){
    return x.b > y.b;
}
bool chk(ll rest){
    for(int i=1;i<=tot1;i++){
        if(rest < a[i].a) return false;
        rest -= a[i].a;
        rest += a[i].b;
    }
    for(int i=1;i<=tot2;i++){
        if(rest < b[i].a) return false;
        rest -= b[i].a;
        rest += b[i].b;
    }
    return true;
}
signed main(){
    n = read();
    for(int i=1;i<=n;i++){
        int x = read(),y = read();
        if(x <= y) a[++tot1] = node{x,y};
        else b[++tot2] = node{x,y};
    }
    sort(a+1,a+1+tot1,cmp); sort(b+1,b+1+tot2,cmp1);
    ll l = 0,r = 1e18,res = 0;
    while(l <= r){
        ll mid = (l+r) >> 1;
        if(chk(mid)) res = mid,r = mid-1;
        else l = mid+1;
    }
    cout << res << "\n";
    return 0;
}