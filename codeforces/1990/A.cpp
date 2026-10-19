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
const int N = 1e5+10;
int n,m,a[N],cnt[N];
bool chk(){
    for(int i=1;i<=n;i++)
        if(cnt[i] & 1) return true;
    return false;
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) cnt[i] = 0;
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        puts(chk() ? "Yes" : "No");
    }
	return 0;
}