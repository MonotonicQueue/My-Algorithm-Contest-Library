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
const int N = 2e5+10;
int n;
using lf = long long;
struct Point{
    lf x,y; int id;
    Point operator+(const Point &o)const{return Point{x+o.x,y+o.y,0};}
    Point operator-(const Point &o)const{return Point{x-o.x,y-o.y,0};}
    Point operator*(const lf &o)const{return Point{x*o,y*o,0};}
    Point operator/(const lf &o)const{return Point{x/o,y/o,0};}
}a[N];
using Line = Point;
lf dot(Line x,Line y){return x.x*y.x+x.y*y.y;}
lf cross(Line x,Line y){return x.x*y.y-x.y*y.x;}
bool vis[N];
struct Convex{
    int m;
    Point c[N];
    void getConvex(vector<Point> v){
        int n = v.size(); m = 0;
        sort(v.begin(),v.end(),[](Point x,Point y){
        return x.x == y.x ? x.y < y.y : x.x < y.x;});
        for(int i=0;i<n;i++){
            while(m > 1 && cross(c[m]-c[m-1],v[i]-c[m]) < 0) m--;
            c[++m] = v[i];
        }
        reverse(v.begin(),v.end());
        int k = m;
        for(int i=1;i<n;i++){
            while(m > k && cross(c[m]-c[m-1],v[i]-c[m]) < 0) m--;
            c[++m] = v[i];
        }
        for(int i=1;i<=m;i++) vis[c[i].id] = true;
    }
}A,B;
void solve(){
    n = read();
    for(int i=1;i<=n;i++)
        a[i].x = read(),a[i].y = read(),a[i].id = i;
    for(int i=1;i<=n;i++) vis[i] = false;
    vector<Point> v;
    for(int i=1;i<=n;i++) v.push_back(a[i]);
    A.getConvex(v);
    v.clear();
    for(int i=1;i<=n;i++) if(!vis[a[i].id]) v.push_back(a[i]);
    B.getConvex(v);
    if(B.m == 0) return puts("-1"),void();
    ll sum = 0,ans = 0;
    for(int i=3;i<A.m;i++) sum += cross(A.c[i-1]-A.c[1],A.c[i]-A.c[i-1]);
    for(int i=2,j=1;i<=A.m;i++){
        while(j < B.m && cross(A.c[i]-A.c[i-1],B.c[j]-A.c[i-1])
         > cross(A.c[i]-A.c[i-1],B.c[j+1]-A.c[i-1])) j++;
        ans = max(ans,sum-cross(A.c[i]-A.c[i-1],B.c[j]-A.c[i-1]));
    }
    cout << ans << "\n";
}
signed main(){
    int T = read();
    while(T--) solve();
    return 0;
}
