#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
const int N = 1e6+10;
int k,a[N],flag[N];
void solve(){
	k = read();
	for(int i=1;i<=k;i++) a[i] = read();
	for(int i=1;i<=k;i++) flag[i] = 0;
	int n = k-2;
	for(int i=1;i<=k;i++) flag[a[i]]++;
	for(int i=1;i*i<=n;i++){
		if(n % i == 0){
			if(i*i != n){
				if(flag[i] && flag[n/i]){
					cout << i << " " << n/i << "\n";
					return ;
				}
			}else{
				if(flag[i] >= 2){
					cout << i << " " << i << "\n";
					return ;
				}
			}
		}
	}
}
int main(){
	int T = read();
	while(T--) solve();
    return 0;
}
