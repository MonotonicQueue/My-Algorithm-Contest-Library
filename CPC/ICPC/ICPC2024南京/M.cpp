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
const double PI = acos(-1);
const double eps = 1e-9;
void solve(){
    int n = read(),X = read(),Y = read();
    double d = read(),t = read(),ans = 0.0;
    auto get = [&](double x){
        if(x < -eps) x += 2*PI;
        if(x > 2*PI+eps) x -= 2*PI;
        return fabs(x);
    };
    double st = get(atan2(Y,X));
    vector<double> vc;
    bool f1 = false,f4 = false;
    for(int i=1;i<=n;i++){
        double x = read(),y = read();
        if(x > 0 && y+d > 0) f1 = true;
        if(x > 0 && y-d < 0) f4 = true;
        double a = get(atan2(y,x));
        double l1 = sqrt(x*x+y*y),l2 = d,l3 = sqrt(l1*l1-l2*l2);
        double b = acos((l1*l1+l3*l3-l2*l2)/(2*l1*l3));
        double a1 = get(a-b),a2 = get(a+b);
        vc.push_back(a1); vc.push_back(a2);
    }
    if(f1 && f4){
        for(auto &x : vc)
            if(x <= PI) x += 2*PI;
        if(st <= PI) st += 2*PI;
    }
    sort(vc.begin(),vc.end());
    double L = vc.front(),R = vc.back();
    if(st < L) t -= L-st,st = L;
    else if(L < st && st < R){
        ans -= st-L;
        t += st-L;
        st = L;
    }else{
        t -= L+2*PI-st;
        st = L;
    }
    if(t < 0) printf("%.12lf",ans);
    else{
        double len = R-L;
        int k = t/PI/2;
        ans += k*len;
        t -= k*2*PI;
        ans += min(t,len);
        printf("%.12lf",ans);
    }
}
int main(){
    int T = 1;
    while(T--) solve();
	return 0;
} 


