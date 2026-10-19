#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pil pair<int,ll>
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
int main(){
    n = read();
    ll sum1 = 0,sum2 = 0,now = 0;
    priority_queue<pair<ll,int>> q1,q2;
    for(int i=1;i<=n;i++){
        ll a = read(),b = read();
        sum1 += a-b; sum2 += b-a;
        now += abs(a-b);
        q1.push(mk(a+b-abs(a-b),i));
        q2.push(mk(-a-b-abs(a-b),i));
    }
    ll ans = max(sum1,sum2);
    while(!q1.empty()){
        ll a = q1.top().fi,b = q2.top().fi;
        if(q1.top().se != q2.top().se)  now += a+b;
        else{
            q1.pop(); q2.pop();
            if(q1.empty()) break;
            now += max(a+q2.top().fi,b+q1.top().fi);
        }
        q1.pop(); q2.pop();
        ans = max(ans,now);
    }
    cout << ans;
	return 0;
}