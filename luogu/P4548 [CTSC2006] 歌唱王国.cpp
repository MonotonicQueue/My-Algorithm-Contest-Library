#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
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
const int mod = 10000;
int n,m,nxt[N],s[N];
ll fpow(ll x,ll k){
    ll res = 1;
    while(k){
        if(k & 1)
            res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
inline void write(int x){
    putchar(x/1000+'0');  x %= 1000;
    putchar(x/100+'0');  x %= 100;
    putchar(x/10+'0');  x %= 10;
    putchar(x+'0'); putchar('\n');
}
int main(){
    n = read(); int T = read();
    while(T--){
        m = read();
        for(int i=1;i<=m;i++) s[i] = read();
        for(int i=2,j=0;i<=m;i++){
            while(j && s[i] != s[j+1]) j = nxt[j];
            if(s[i] == s[j+1]) j++;
            nxt[i] = j;
        }
        int x = m,ans = 0;
        while(x){
            ans = (ans+fpow(n,x))%mod;
            x = nxt[x];
        }
        write(ans);
    }
	return 0;
}
