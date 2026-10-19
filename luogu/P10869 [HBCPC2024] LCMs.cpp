#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mk make_pair
#define fi first
#define se second
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}

int main(){
    int T = read();
    while(T--){
        ll a = read(),b = read();
        if(a == b){
            cout << "0\n";
            continue;
        }
        ll d = __gcd(a,b);
        if(d != 1) cout << min(a+b,a*b/d) << "\n";
        else{
            ll t = b,k = a;
            for(int i=2;i*i<=b;i++)
                if(b % i == 0){
                    t = i;
                    break;
                }
            for(int i=2;i*i<=a;i++)
                if(a % i == 0){
                    k = i;
                    break;
                }
            ll res = 0;
            if(t != b) res += b;
            if(k != a) res += a;
            ll ans = a*b;
            ans = min(ans,res+t*k);
            ans = min(ans,res+2*(t+k));
            cout << ans << "\n";
        }
    }
	return 0;
}
