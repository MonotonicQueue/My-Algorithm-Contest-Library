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
const int N = 1e5+10;
int n;
long double p[N],ans,t;
int main(){
    n = read();
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++){
        ans += (2*t+1)*p[i];
        t = p[i]*(t+1);
    }
    printf("%.10Lf",ans);
	return 0;
}
