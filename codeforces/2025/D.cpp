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
const int N = 2e6+10;
const int M = 5010;
int n,m,a[N];
int f[M],pre[M],suf[M];
int main(){
    n = read(); m = read();
    for(int i=1;i<=n;i++) a[i] = read();
    a[++n] = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == 0){
            for(int j=1;j<=sum;j++) pre[j] += pre[j-1],f[j] += pre[j];
            for(int j=sum;j>=0;j--) suf[j] += suf[j+1],f[j] += suf[j];
            sum++;
            for(int j=0;j<=sum;j++) pre[j] = suf[j] = 0;
            for(int j=sum;j;j--) f[j] = max(f[j],f[j-1]);
        }
        if(a[i] > 0 &&  a[i] <= sum) pre[a[i]]++;
        if(a[i] < 0 && -a[i] <= sum) suf[sum+a[i]]++;
    }
    int ans = 0;
    for(int i=0;i<=sum;i++) ans = max(ans,f[i]);
    cout << ans;
    return 0;
}