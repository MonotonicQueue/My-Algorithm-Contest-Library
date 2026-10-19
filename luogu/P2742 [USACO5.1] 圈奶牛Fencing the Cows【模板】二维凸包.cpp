#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n;
struct Point{
	double x,y;
	Point operator + (const Point &o){return Point{x+o.x,y+o.y};}
	Point operator - (const Point &o){return Point{x-o.x,y-o.y};}
}a[N];
double slope(Point x,Point y){
	return x.x-y.x != 0 ? (x.y-y.y)/(x.x-y.x) : 1e9;
}
double dis(Point x,Point y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
bool cmp(Point x,Point y){
	return x.x != y.x ? x.x < y.x : x.y < y.y;
}
int st[N],top;
int main(){
	n = read();
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	double ans = 0.0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		while(top > 1 && slope(a[i],a[st[top-1]]) < slope(a[st[top]],a[st[top-1]])) top--;
		st[++top] = i;
	}
	for(int i=1;i<top;i++) ans += dis(a[st[i]],a[st[i+1]]);
	top = 0;
	for(int i=n;i;i--){
		while(top > 1 && slope(a[i],a[st[top-1]]) < slope(a[st[top]],a[st[top-1]])) top--;
		st[++top] = i;
	}
	for(int i=1;i<top;i++) ans += dis(a[st[i]],a[st[i+1]]);
	printf("%.2lf",ans);
	return 0;
}
