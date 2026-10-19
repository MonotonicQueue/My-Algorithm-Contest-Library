#include<bits/stdc++.h>
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
const int N = 4e5+10;
int n,k;
char a[N];
int stk[N],top;
void solve(){
    n = read(); k = read();
    scanf("%s",a+1);
    int cnt = 0;
    k = min(k,n/2);
    top = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == '('){
            cnt++;
            int d = top+1,x = cnt-d;
            int pos = lower_bound(stk+1,stk+1+top,x-k)-stk-1;
            ans = max(ans,d-pos);
            if(x <= k) ans = max(ans,k+d);
            stk[++top] = x;
        }else top--;
    }
    cout << min(ans,n/2) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}

