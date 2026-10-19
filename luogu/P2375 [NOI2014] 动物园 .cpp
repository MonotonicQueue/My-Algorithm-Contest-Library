#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
const int mod = 1e9+7;
const int N = 1e6+10;
char ch[N];
int nxt[N],ans[N];
signed main(){
	int T = read();
    while(T--){
        cin >> ch+1;
        int n = strlen(ch+1);
        for(int i=1;i<=n;i++) ans[i] = nxt[i] = 0;
        ans[1] = 1;
        for(int i=2,j=0;i<=n;i++){
            while(j && ch[i] != ch[j+1]) j = nxt[j];
            if(ch[i] == ch[j+1]) j++;
            nxt[i] = j; ans[i] = ans[j]+1;
        }
        ll res = 1;
        for(int i=2,j=0;i<=n;i++){
            while(j && ch[i] != ch[j+1]) j = nxt[j];
            if(ch[i] == ch[j+1]) j++;
            while((j<<1) > i) j = nxt[j];
            res = res*(ans[j]+1)%mod;
        }
        cout << res << "\n";
    }
	return 0;
}

//g++ -std=c++14 -O2 -Wall -o 1st 1st.cpp