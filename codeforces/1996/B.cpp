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
const int N = 1e3+10;
int n,k;
char a[N][N];
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        for(int i=1;i<=n;i+=k){
            for(int j=1;j<=n;j+=k){
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
	return 0;
}
