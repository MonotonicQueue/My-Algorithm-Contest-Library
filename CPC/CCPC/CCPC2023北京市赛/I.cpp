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
int n;
ll a[N][N],d[N][N];
bool flag[N][N];
int main(){
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) d[i][j] = a[i][j] = read();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i != j && j != k && i != k && d[i][k]+d[k][j] <= d[i][j])
                    d[i][j] = d[i][k]+d[k][j],flag[i][j] = true;
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(flag[i][j] || i == j) cout << "0";
            else cout << "1";
        }
        cout << "\n";
    }
	return 0;
}