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
int n;
int main(){
    string s;
    cin >> s;
    s += '0';
    int cnt = 0;
    double ans = 0,q = sqrt(2);
    for(auto x : s){
        if(x == '0'){
            if(cnt == 0) continue;
            if(cnt & 1) ans += (cnt+1)/2;
            else ans += cnt/2-1+q;
            cnt = 0;
        }else cnt++;
    }
    printf("%.12lf",ans);
	return 0;
}