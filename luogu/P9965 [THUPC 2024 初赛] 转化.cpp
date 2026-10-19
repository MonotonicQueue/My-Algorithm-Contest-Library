#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
int n,totb,totc;
struct node{
    ll a,b,c,id;
}a[N],b[N],c[N];
ll ans[N];

int main(){
    n = read();
    for(int i=1;i<=n;i++) a[i].a = read();
    for(int i=1;i<=n;i++) a[i].b = read();
    for(int i=1;i<=n;i++) a[i].c = read();
    for(int i=1;i<=n;i++) a[i].id = i;
    for(int i=1;i<=n;i++)
        if(a[i].a != 0) b[++totb] = a[i];
        else c[++totc] = a[i];
    ll s1 = 0,s2 = 0;
    for(int i=1;i<=totc;i++)
        s2 += max(min(c[i].c,c[i].b-1),0ll);
    
    for(int i=1;i<=totb;i++) s1 += min(b[i].a+b[i].c,b[i].b);
    for(int i=1;i<=totb;i++){
        ll mx = s1-min(b[i].a+b[i].c,b[i].b)+b[i].a+b[i].c;
        if(s1) mx += s2;
        ans[b[i].id] = mx;
    }
    for(int i=1;i<=totc;i++){
        ll mx = s1;
        if(s1) mx += s2+c[i].c-max(min(c[i].c,c[i].b-1),0ll);
        ans[c[i].id] = mx;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
    ll sum = 0;
    for(int i=1;i<=n;i++)
        if(a[i].a) sum += a[i].a+a[i].c;
    if(s1){
        for(int i=1;i<=totc;i++)
            if(c[i].b) sum += c[i].c,s1 += min(c[i].c,c[i].b-1);
        sort(c+1,c+1+totc,[](node x,node y){return x.c > y.c;});
        for(int i=1;i<=totc;i++){
            if(c[i].b) continue;
            sum += c[i].c;
            s1--;
            if(!s1) break;
        }
    }
    cout << sum;
    return 0;
}