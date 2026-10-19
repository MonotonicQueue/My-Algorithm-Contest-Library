#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 1e6+10;
ull P = 1331,pw[N];
int n,m;
char s[N],t[N];
ull pre[N],suf[N],g[N];
ull spre(int l,int r){
    return pre[r]-pre[l-1]*pw[r-l+1];
}
ull ssuf(int l,int r){
    return suf[l]-suf[r+1]*pw[r-l+1];
}
ull tpre(int l,int r){
    return g[r]-g[l-1]*pw[r-l+1];
}
int a[N];
int main(){
    scanf("%s%s",s+1,t+1);
    n = strlen(s+1);
    m = strlen(t+1);
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = pw[i-1]*P;
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]*P+s[i];
        g[i] = g[i-1]*P+t[i];
    }
    for(int i=n;i;i--){
        suf[i] = suf[i+1]*P+s[i];
    }
    for(int i=1;i<=n;i++){
        int l = 0,r = min(n-i,i-1),tar = 0;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(spre(i-mid,i) == ssuf(i,i+mid)) tar = mid,l = mid+1;
            else r = mid-1;
        }
        a[i-tar]++; a[i+1]--;
        // cout << i << " " << tar << "\n";
        if(i == n) continue;
        l = 0,r = min(n-i-1,i-1),tar = -1;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(spre(i-mid,i) == ssuf(i+1,i+mid+1)) tar = mid,l = mid+1;
            else r = mid-1;
        }
        a[i-tar]++; a[i+1]--;
        // cout << i << " " << tar << "\n";
    }
    for(int i=1;i<=n+1;i++) a[i] += a[i-1];
    // for(int i=1;i<=n;i++) cout << a[i] << " ";
    // cout << "\n";
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int l = 0,r = min(m,i),tar = 0;
        while(l <= r){
            int mid = (l+r) >> 1;
            if(ssuf(i-mid+1,i) == g[mid]) tar = mid,l = mid+1;
            else r = mid-1;
        }
        ans += 1ll*tar*a[i+1];
    }
    cout << ans;
	return 0;
}