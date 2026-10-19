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
const int N = 510;
int n,m,a[N][N],b[N][N];
bool chk(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j] != b[i][j]) return false;
    return true;
}
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                char ch; cin >> ch;
                a[i][j] = ch-'0';
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                char ch; cin >> ch;
                b[i][j] = ch-'0';
            }
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++){
                int c = (b[i][j]-a[i][j]+3)%3;
                if(c == 1){
                    a[i][j] = (a[i][j]+1)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+1)%3;
                    a[i+1][j] = (a[i+1][j]+2)%3;
                    a[i][j+1] = (a[i][j+1]+2)%3;
                }else if(c == 2){
                    a[i][j] = (a[i][j]+2)%3;
                    a[i+1][j+1] = (a[i+1][j+1]+2)%3;
                    a[i+1][j] = (a[i+1][j]+1)%3;
                    a[i][j+1] = (a[i][j+1]+1)%3;
                }
            }
        // for(int i=1;i<=n;i++,puts(""))
        //     for(int j=1;j<=m;j++) cout << a[i][j] << " ";
        puts(chk() ? "YES" : "NO");
    }
	return 0;
}
