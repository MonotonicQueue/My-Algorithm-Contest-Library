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
int id[1010];
char g[25][25];
void solve(){
    int n = read();
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            string w;
            w += string(r-1,'U');
            w += string(n-r,'D');
            w += string(c-1,'L');
            w += string(n-c,'R');
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++) g[i][j] = '1';
            for(int j=1;j<=n;j++)
                if(j != c && !(c > 1 && j == c-1)) g[r][j] = '0';
            for(int i=1;i<=n;i++){
                if(i == r) continue;
                int t;
                if(i < r) t = i-1;
                else t = r-1+n-i;
                int q = (id[w[t+1]]-id[w[t]]+n) % 4;
                for(int j=1;j<=q;j++) g[i][j] = '0';
            }
            for(int i=1;i<=n;i++,puts(""))
                for(int j=1;j<=n;j++) cout << g[i][j];
        }
    }
    string sss = "DRLU";
    for(int i=0;i<=n*n;i++) cout << sss[i%4];
}
int main(){
    id['D'] = 0; id['R'] = 1;
    id['L'] = 2; id['U'] = 3;
    int T = 1;
    while(T--) solve();
    return 0;
}

