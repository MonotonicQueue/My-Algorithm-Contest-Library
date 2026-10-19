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
const int N = 1e7+10;
int n,p[N],ls[N],rs[N];
int s[N],top;
inline void build(){
    for(int i=1;i<=n;i++){
        int k = top;
        while(k && p[s[k]] > p[i]) k--;
        if(k) rs[s[k]] = i;
        if(k < top) ls[i] = s[k+1];
        s[++k] = i;
        top = k;
    }
}
int main(){
    n = read();
    for(int i=1;i<=n;i++) p[i] = read();
    build();
    ll ans1 = 0, ans2 = 0;
    for(int i=1;i<=n;i++) 
        ans1 ^= 1ll*i*(ls[i]+1),
        ans2 ^= 1ll*i*(rs[i]+1);
    cout << ans1 << " " << ans2;
	return 0;
}
