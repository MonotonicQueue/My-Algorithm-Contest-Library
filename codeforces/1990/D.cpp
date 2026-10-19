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
int n,a[N];
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++)
            if(a[i] == 1) a[i] = 2;
            else if(a[i] == 3) a[i] = 4;
        int ans = n;
        a[n+1] = -1;
        for(int i=1;i<=n;i++){
            if(a[i] == 0) ans--;
            else if(a[i] == 2){
                int j=i+1;
                for(;j<=n;j++)
                    if(a[j] != 4) break;
                if(a[j] == 2 && (j-i-1)%2 == 0) ans--,i=j;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}