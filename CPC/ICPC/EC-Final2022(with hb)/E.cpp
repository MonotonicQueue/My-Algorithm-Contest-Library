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
struct Point{
	double x,y;
	Point(double x=0,double y=0): x(x),y(y){}
	Point operator*(const double a){
		return Point(a*x,y*a);
	}
	Point operator/(const double a){
		return Point(x/a,y/a);
	}
	Point operator+(const Point &o){
		return Point(x+o.x,y+o.y);
	}
	Point operator-(const Point &o){
		return Point(x-o.x,y-o.y);
	}
	double operator*(const Point &o){
		return x*o.x+y*o.y;
	}
	double norm(){
		return sqrt(x*x+y*y);
	}
};
double dis(Point x,Point y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
double cross(Point x,Point y){
	return x.x*y.y-x.y*y.x;
}
const int N = 110;
Point S[N],T[N];
void solve(){
	Point P[4],Q[4];
	for(int i=0;i<4;i++){
		int x = read(),y = read();
		P[i] = Point(x,y);
	}
	for(int i=0;i<4;i++){
		int x = read(),y = read();
		Q[i] = Point(x,y);
	}
	S[0].x = read(); S[0].y = read();
	T[0].x = read(); T[0].y = read();
	int k = read(),n = read();
	auto cov = [&](Point x)->Point{
		x = x-P[0];
		return Q[0]+(Q[1]-Q[0])*(x*(P[1]-P[0])/(P[1]-P[0]).norm()/(P[1]-P[0]).norm())
				   +(Q[3]-Q[0])*(x*(P[3]-P[0])/(P[3]-P[0]).norm()/(P[3]-P[0]).norm());
	};
	for(int i=1;i<=n;i++) S[i] = cov(S[i-1]);
	for(int i=1;i<=n;i++) T[i] = cov(T[i-1]);
	double ans = 1e18;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			ans = min(ans,(i+j)*k+dis(S[i],T[j]));
		}
	}
	printf("%.10lf\n",ans);
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}