#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
int n;
struct Point{
	double x,y;
	Point operator - (const Point &o)const{
		return Point{x-o.x,y-o.y};
	}
}a[N];
double cross(Point x,Point y){
	return x.x*y.y-y.x*x.y;
}
int main(){
    int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++){
			a[i].x = read();
			a[i].y = read();
		}
		double ans = 1e18;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++){
					double res = abs(cross(a[j]-a[i],a[k]-a[i]));
					if(res != 0) ans = min(ans,res);
				}
		if(ans == 1e18) cout << "-1\n";
		else printf("%.10lf\n",ans/2);
	}
	return 0;
}