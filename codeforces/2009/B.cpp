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
const int N = 1e5;
char s[N][10];
void solve(){
    int n = read();
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=n;i;i--){
        for(int j=1;j<=4;j++)
            if(s[i][j] == '#') cout << j << " ";
    }
    cout << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
    return 0;
}
