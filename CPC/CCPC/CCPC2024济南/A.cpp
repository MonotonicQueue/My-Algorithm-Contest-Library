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
const int N = 210;
int n,m,k,tot;
string s[N*N];
void solve(){
    n = read(); m = read(); k = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int l=1;l<=k;l++){
                char ch; cin >> ch;
                s[(i-1)*m+j] += ch;
            }
    if(s[1] != s[2] && s[2] == s[3]){
        cout << "1 1\n";
    }else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) if(s[(i-1)*m+j] != s[1]){
                cout << i << " " << j << "\n";
            }
    }
}
int main(){
    int T = 1;
    while(T--) solve();
	return 0;
}