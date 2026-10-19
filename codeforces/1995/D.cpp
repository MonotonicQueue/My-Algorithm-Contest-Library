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
int n,c,k;
int cnt[N],f[N];
char s[N];
int main(){
    int T = read();
    while(T--){
        n = read(); c = read(); k = read();
        for(int i=0;i<c;i++) cnt[i] = 0;
        for(int i=0;i<(1<<c);i++) f[i] = 0;
        cin >> (s+1);
        int sta = (1<<c)-1;
        for(int i=1;i<=k;i++){
            int d = s[i]-'A';
            if(!cnt[d]) sta ^= 1<<d;
            cnt[d]++;
        }
        f[sta] = 1;
        for(int i=k+1;i<=n;i++){
            int d = s[i]-'A';
            if(!cnt[d]) sta ^= 1<<d;
            cnt[d]++;
            d = s[i-k]-'A';
            cnt[d]--;
            if(!cnt[d]) sta ^= 1<<d;
            f[sta] = 1;
            // cout << sta << "\n";
        }
        f[(1<<c)-1-(1<<(s[n]-'A'))] = 1;
        for(int i=0;i<c;i++)
            for(int j=0;j<(1<<c);j++)
                if((j >> i) & 1) f[j-(1<<i)] |= f[j];
        int ans = 114514;
        for(int i=0;i<(1<<c);i++)
            if(!f[i]) ans = min(ans,__builtin_popcount(i));
        cout << ans << "\n";
    }
	return 0;
}
/*
1
3 2 2
AAB
*/