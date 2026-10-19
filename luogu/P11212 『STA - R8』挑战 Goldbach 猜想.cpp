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
const int N = 2e5+10;
int n,q;
int pr[N],cnt,ans[N];
bool vis[N];
void init(int n = 2e5){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++cnt] = i;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
			vis[i*pr[j]] = true;
			if(i % pr[j] == 0) break; 
		}
	}
}
int main(){
	n = 2e5;
	init();
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<i;j++)
			for(int k=1;k*pr[i]+pr[j]<=n;k++) ans[k*pr[i]+pr[j]]++;
	int Q = read();
	while(Q--) cout << ans[read()] << "\n";
    return 0;
}