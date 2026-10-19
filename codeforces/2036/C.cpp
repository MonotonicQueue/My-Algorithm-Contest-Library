#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 2e5+10;
int n;
char s[N];
bool chk(int x){
    if(x+3 > n || x < 0) return false;
    return s[x] == '1' && s[x+1] == '1' && s[x+2] == '0' && s[x+3] == '0';
}
void solve(){
    scanf("%s",s+1);
    n = strlen(s+1);
    int sum = 0;
    for(int i=1;i<=n;i++) sum += chk(i);
    int Q = read();
    while(Q--){
        int x = read(); char v; cin >> v;
        for(int i=x-4;i<=x+4;i++) sum -= chk(i);
        s[x] = v;
        for(int i=x-4;i<=x+4;i++) sum += chk(i);
        puts(sum ? "Yes" : "No");
    }
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}