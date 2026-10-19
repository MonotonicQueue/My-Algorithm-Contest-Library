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
const int N = 1e6+10;
int n,a,b;
char s[N];
void solve(){
    n = read(); a = read(); b = read();
    scanf("%s",s+1);
    int T = 100,x = 0,y = 0;
    while(T--){
        for(int i=1;i<=n;i++){
            if(s[i] == 'N') y++;
            if(s[i] == 'S') y--;
            if(s[i] == 'W') x--;
            if(s[i] == 'E') x++;
            if(x == a && y == b) return puts("YES"),void();
        }
    }
    puts("NO");
}
int main(){
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}