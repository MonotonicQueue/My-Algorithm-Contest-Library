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
const int N = 2010;
int n,m,k;
char s[N][N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read(); k = read();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) s[i][j] = '.';
        for(int i=1;i<=min(n,m) && k;i++){
            k--;
            s[i][i] = 'S';
            if(!k) break;
        }
        for(int i=1;i<=n && k;i++){
            for(int j=1;j<=m && k;j++){
                if(s[i][j] == '.'){
                    k--;
                    s[i][j] = 'S';
                }
            }
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++) cout << s[i][j];
    }
    return 0;
}
