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
const int N = 1e5+10;
int n,m,a[N];
int main(){
    int T = read();
    while(T--){
        n = read(); m = read();
        for(int i=1;i<=n*m;i++) a[i] = read();
        if(n*m == 1){
            puts("-1");
            continue;
        }
        a[n*m+1] = a[1];
        for(int i=2;i<=n*m+1;i++){
            cout << a[i] << " ";
            if((i-1) % m == 0) cout << "\n";
        }
    }
	return 0;
}
