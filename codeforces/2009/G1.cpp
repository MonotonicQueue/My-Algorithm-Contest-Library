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
int n,q,k,a[N];
int cnt[N],ans[N];
multiset<int> s;
void solve(){
    n = read(); k = read(); q = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=n;i++) a[i] = a[i]+n-i+1;
    for(int i=1;i<=2*n;i++) cnt[i] = 0;
    s.clear();
    for(int i=1;i<=n;i++){
        if(i > k){
            ans[i-k] = k-*s.rbegin();
            s.erase(s.find(cnt[a[i-k]]));
            cnt[a[i-k]]--;
            if(cnt[a[i-k]]) s.insert(cnt[a[i-k]]);
        }
        if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
        cnt[a[i]]++;
        s.insert(cnt[a[i]]);
    }
    ans[n-k+1] =  k-*s.rbegin();
    while(q--){
        int l = read(),r = read();
        printf("%d\n",ans[l]);
    }
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
