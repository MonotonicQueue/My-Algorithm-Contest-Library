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
int n,k;
int cnt[N];
int main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        if(n >= 2){
            cnt[n] = 1;
            for(int i=n-1;i>=1;i--) cnt[i] = 2;
        }else cnt[1] = 1;
        
        int ans = 0;
        for(int i=n;i && k>0;i--){
            while(k>0 && cnt[i]){
                k -= i;
                ans++;
                cnt[i]--;
            }
        }
        cout << ans << "\n";
    }
	return 0;
}