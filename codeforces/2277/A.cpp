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
const int N = 3010;
int n,k;
int a[N],cnt[N];
void solve(){
    n = read(); k = read();
    cnt[0] = 0;
    for(int i=1;i<=n;i++){
        cnt[i] = 0;
        a[i] = read();
    }
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    int now = 0,pos = 0;
    for(int i=0;i<=n;i++){
        now += cnt[i];
        if(now < k*(i+1) || !cnt[i]){
            pos = i;
            break;
        }
    }
    cout << pos << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
