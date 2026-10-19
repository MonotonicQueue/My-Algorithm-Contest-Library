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
const int N = 2e5+10;
int n,a[N],b[N];
int t[N];
void add(int x,int y){
    while(x <= 200000){
        t[x] += y;
        x += x&(-x);
    }
}
int ask(int x){
    int res = 0;
    while(x){
        res += t[x];
        x -= x&(-x);
    }
    return res;
}
int cnt[N];
bool chk(){
    for(int i=1;i<=n;i++) if(cnt[a[i]] || cnt[b[i]]) return false;
    return true;
}
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[i] = read();
        for(int i=1;i<=n;i++) cnt[a[i]] = cnt[b[i]] = 0;
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        for(int i=1;i<=n;i++) cnt[b[i]]--;
        if(!chk()){
            puts("NO");
            continue;
        }
        ll rs1 = 0,rs2 = 0;
        for(int i=1;i<=n;i++){
            rs1 += ask(a[i]);
            add(a[i],1);
        }
        for(int i=1;i<=n;i++) add(a[i],-1);
        for(int i=1;i<=n;i++){
            rs2 += ask(b[i]);
            add(b[i],1);
        }
        for(int i=1;i<=n;i++) add(b[i],-1);
        if(rs1 % 2  == rs2 % 2) puts("YES");
        else puts("NO");
    }
	return 0;
}
