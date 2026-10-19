#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
#define pii pair<int,int>
#define pli pair<ll,int>
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
const double inf = 1e12;
int n,q;
double f[32][22],g[32][33],ans[N];
double pw2[40],pw3[32];
struct node{
    double p;
    int t,x;
}a[N];
pair<double,int> b[N];
int main(){
    // freopen("ship.in","r",stdin);
    // freopen("ship.out","w",stdout);
    pw2[0] = pw3[0] = 1;
    for(int i=1;i<=30;i++) pw2[i] = pw2[i-1]*2;
    for(int i=1;i<=20;i++) pw3[i] = pw3[i-1]*3;
    n = read(); q = read();
    for(int i=1;i<=n;i++){
        int p = read(),t = read(),x = read();
        a[i] = node{(double)p,t,x};
    }
    for(int i=1;i<=q;i++){
        b[i].fi = read();
        b[i].se = i;
    }
    sort(b+1,b+1+q);
    for(int p1=0;p1<=30;p1++)
        for(int p2=0;p2<=20;p2++) f[p1][p2] = inf;
    f[0][0] = 0;
    for(int i=1,j=0;i<=q;i++){
        while(j <= n && a[j+1].p <= b[i].fi){
            j++;
            for(int p1=0;p1<=30;p1++)
                for(int p2=0;p2<=20;p2++)
                    g[p1][p2] = f[p1][p2]+(a[j].p-a[j-1].p)/pw2[p1]/pw3[p2];
            if(a[j].x == 2){
                for(int p1=30;p1>=1;p1--)
                    for(int p2=20;p2>=0;p2--) g[p1][p2] = min(g[p1][p2],g[p1-1][p2]+a[j].t);
            }
            if(a[j].x == 3){
                for(int p1=30;p1>=0;p1--)
                    for(int p2=20;p2>=1;p2--) g[p1][p2] = min(g[p1][p2],g[p1][p2-1]+a[j].t);
            }
            if(a[j].x == 4){
                for(int p1=30;p1>=2;p1--)
                    for(int p2=20;p2>=0;p2--) g[p1][p2] = min(g[p1][p2],g[p1-2][p2]+a[j].t);
            }
            for(int p1=0;p1<=30;p1++)
                for(int p2=0;p2<=20;p2++) f[p1][p2] = g[p1][p2];
        }
        ans[b[i].se] = inf;
        for(int p1=0;p1<=30;p1++)
            for(int p2=0;p2<=20;p2++) ans[b[i].se] = min(ans[b[i].se],f[p1][p2]+(b[i].fi-a[j].p)/pw2[p1]/pw3[p2]);
    }
    for(int i=1;i<=q;i++) printf("%.10lf\n",ans[i]);
	return 0;
}