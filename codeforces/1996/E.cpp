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
const int N = 4e5+10;
const int mod = 1e9+7;
int n,m;
char s[N];
vector<int> v[N];
int main(){
    int T = read();
    while(T--){
        cin >> s+1;
        n = strlen(s+1);
        for(int i=0;i<=n*2;i++) v[i].clear();
        int sum = 0;
        v[n].push_back(0);
        for(int i=1;i<=n;i++){
            if(s[i] == '0') sum--;
            else sum++;
            v[sum+n].push_back(i);
        }
        ll ans = 0;
        for(int xx=0;xx<=n*2;xx++){
            ll s = 0;
            for(int l : v[xx]){
                ans = (ans+s*(n-l+1))%mod;
                s = (s+l+1)%mod;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
