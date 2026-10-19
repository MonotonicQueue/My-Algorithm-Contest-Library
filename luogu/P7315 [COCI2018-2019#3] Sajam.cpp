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
const int N = 1010;
int n,k;
bitset<N> a[N];
bool chk(int x){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(i == x) continue;
        a[i] ^= a[x];
        cnt += min(a[i].count(),n-a[i].count());
        a[i] ^= a[x];
    }
    return cnt <= k;
}
void solve(){
    if(n == k){
        k--;
        for(int i=1;i<=n;i++){
            a[1].flip(i);
            if(chk(1)){
                puts("DA");
                return ;
            }
            a[1].flip(i);
        }
        k++;
    }
    for(int i=1;i<=n;i++)
        if(chk(i)){
            puts("DA");
            return ;
        }
    puts("NE");
}
int main(){
    n = read(); k = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char ch; cin >> ch;
            a[i][j] = ch == 'o';
        }
    solve();
	return 0;
}
