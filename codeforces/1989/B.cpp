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
int n,m;
char a[N],b[N];
int main(){
    int T = read();
    while(T--){
        cin >> a+1 >> b+1;
        n = strlen(a+1); m = strlen(b+1);
        int ans = 1e9;
        for(int j=1;j<=m;j++){
            int pos = j,res = 0;
            for(int i=1;i<=n;i++)
                if(pos <= m && a[i] == b[pos]) pos++,res++;
            ans = min(ans,n+m-res);
        }
        cout << ans << "\n";
    }
	return 0;
}
