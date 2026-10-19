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
char s[N];
int stk[N],top;
int cnt[2][3];
void solve(){
    scanf("%s",s+1);
    n = strlen(s+1);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        int c = s[i]-'0';
        cnt[i%2][c]++;
    }
    int s1 = cnt[0][0]-cnt[1][0],s2 = cnt[0][1]-cnt[1][1];
    if(s1 < 0){
        int k = min(-s1,cnt[0][2]);
        s1 += k; cnt[0][2] -= k;
    }
    if(s2 < 0){
        int k = min(-s2,cnt[0][2]);
        s2 += k; cnt[0][2] -= k;
    }
    s1 += cnt[0][2];
    if(s1 > 0){
        int k = min(s1,cnt[1][2]);
        s1 -= k; cnt[1][2] -= k;
    }
    if(s2 > 0){
        int k = min(s2,cnt[1][2]);
        s2 -= k; cnt[1][2] -= k;
    }
    s1 -= cnt[1][2];
    cout << abs(s1)+abs(s2) << "\n";
}
int main(){
    int T = read();
    while(T--) solve();
	return 0;
} 


