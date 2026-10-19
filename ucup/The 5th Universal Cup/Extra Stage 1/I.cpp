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
const int N = 1e6+10;
int n,k;
char a[N];
int p[N],w[N];
void solve(){
    n = read(); k = read();
    scanf("%s",a+1);
    int d = __gcd(k,26);
    for(int i=0;i<d;i++) p[i] = w[i] = 0;
    for(int i=1;i<=n;i++){
        p[(a[i]-'a')%d]++;
        w[(a[i]-'a')%d] += (a[i]-'a')/d;
    }
    if(n == 2){
        if(a[1] == a[2]) puts("Yes");
        else puts("No");
        return ;
    }
    int cnt = 0,num = 0;
    bool flag = true;
    for(int i=0;i<d;i++){
        if(p[i] & 1) cnt++;
        num += w[i]; 
    }
    if(cnt > 1) flag = false;
    if(cnt == 0 && num % 2 == 1 && (d & 1)) flag = false;
    puts(flag ? "Yes" : "No");
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
