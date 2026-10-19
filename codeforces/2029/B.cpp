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
const int N = 1e6+10;
int n;
char s[N],t[N];
void solve(){
    n = read();
    scanf("%s",s+1);
    scanf("%s",t+1);
    int cnt0 = 0,cnt1 = 0;
    for(int i=1;i<=n;i++)
        if(s[i] == '0') cnt0++;
        else cnt1++;
    for(int i=1;i<n;i++){
        int num = t[i]-'0';
        if(!cnt0 || !cnt1){
            return puts("NO"),void();
        }
        if(num == 0) cnt1--;
        else cnt0--;
    }
    puts("YES");
}
int main(){
	int T = read();
    while(T--) solve();
    return 0;
}
