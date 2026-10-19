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
const int N = 110;
int n,m;
char s[N],t[N];
int main(){
    int T = read();
    while(T--){
        scanf("%s%s",s+1,t+1);
        n = strlen(s+1); m = strlen(t+1);
        int ans = n+m;
        for(int i=1;i<=min(n,m);i++){
            if(s[i] == t[i]) ans--;
            else break;
        }
        cout << min(n+m,ans+1) << "\n";
    }
    return 0;
}