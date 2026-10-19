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
const int mod = 1e9+7;
int n,m;
char a[N],b[N];
int kmp[N];
ll f[N],g[N],sum[N];
int main(){
	scanf("%s%s",a+1,b+1);
    n = strlen(a+1); m = strlen(b+1);
    for(int i=2,j=0;i<=m;i++){
        while(j && b[i] != b[j+1]) j = kmp[j];
        if(b[i] == b[j+1]) j++;
        kmp[i] = j;
    }
    ll ans = 0;
    for(int i=1,j=0;i<=n;i++){
        while(j && a[i] != b[j+1]) j = kmp[j];
        if(a[i] == b[j+1]) j++;
        if(j == m){
            j = kmp[j];
            f[i] = (sum[i-m]+i-m+1)%mod;
            g[i] = (g[i-1]+f[i])%mod;
            sum[i] = (sum[i-1]+g[i])%mod;
        }else{
            f[i] = f[i-1];
            g[i] = (g[i-1]+f[i])%mod;
            sum[i] = (sum[i-1]+g[i])%mod;
        }
    }
    cout << g[n];
	return 0;
}

