#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,in[N];
signed main(){
	int T = read();
    while(T--){
        n = read();
        memset(in,0,sizeof(in));
        for(int i=1;i<n;i++){
            int u = read(),v = read();
            in[u]++; in[v]++;
        }
        bool flag = false;
        for(int i=1;i<=n;i++)
            if(in[i] % 2 == 0) flag = true;
        puts(flag ? "Hifuu" : "Luna");
    }
	return 0;
}

