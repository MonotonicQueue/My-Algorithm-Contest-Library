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
const int N = 2010;
int n,a,b;
double p[N],u[N];
struct node{
    double x;
    int c1,c2;
    bool operator<(const node &o)const{
        return x > o.x;
    }
}t[N];
double ans;
bool chk(double mid){
    ans = 0;
    for(int i=1;i<=n;i++){
        if(u[i]-p[i]*u[i]-mid > 0) t[i].x = p[i]+u[i]-p[i]*u[i]-mid,t[i].c1 = 1;
        else t[i].x = p[i],t[i].c1 = 0;
        if(u[i]-mid > 0) t[i].x -= u[i]-mid,t[i].c2 = 1,ans += u[i]-mid;
        else t[i].c2 = 0;
    }
    sort(t+1,t+1+n);
    int cnt = 0;
    for(int i=1;i<=a;i++) cnt += t[i].c1,ans += t[i].x;
    for(int i=a+1;i<=n;i++) cnt += t[i].c2;
    return cnt < b;
}
int main(){
    n = read(); a = read(); b = read();
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&u[i]);
    double l = 0,r = 1;
    int T = 60;
    while(T--){
        double mid = (l+r)/2.0;
        if(chk(mid)) r = mid;
        else l = mid;
    }
    printf("%.8lf",ans+l*b);
    return 0;
}