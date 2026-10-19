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
const int mod1 = 1145141;
const int mod2 = 998244353;
int n,k,a[N],val[2];
ull pre1[N],suf1[N],pre2[N],suf2[N],P1=131,P2=13131,pw1[N],pw2[N];
int main(){
	int T = read();
    while(T--){
    	n = read(); k = read();
        for(int i=1;i<=n;i++){
            char ch; cin >> ch;
            if(ch == '0') a[i] = 37894;
            else a[i] = 12321;
        }
        val[0] = 37894; val[1] = 12321;
        pw1[0] = pw2[0] = 1;
        for(int i=1;i<=n;i++) pw1[i] = pw1[i-1]*P1,pw2[i] = pw2[i-1]*P2;
        for(int i=1;i<=n+1;i++)
            pre1[i] = suf1[i] = pre2[i] = suf2[i] = 0;
        for(int i=1;i<=n;i++){
            pre1[i] = pre1[i-1]+a[i]*pw1[i-1];
            pre2[i] = pre2[i-1]+a[i]*pw2[i-1];
        }
        for(int i=n;i;i--){
            suf1[i] = suf1[i+1]+a[i]*pw1[n-i];
            suf2[i] = suf2[i+1]+a[i]*pw2[n-i];
        }
        ull ans1 = 0,ans2 = 0;
        for(int i=1,j=0,h=0;i<=n;i++){
            ans1 = ans1*P1+val[h];
            ans2 = ans2*P2+val[h];
            j++;
            if(j == k) j = 0,h ^= 1;
        }
        ll res = -1;
        for(int i=1;i<=n;i++){
            ull sum1 = 0,sum2 = 0,sum3 = 0;
            sum1 = suf1[i+1]*pw1[i]+pre1[i];
            sum2 = suf2[i+1]*pw2[i]+pre2[i];
            if(sum1 == ans1 && sum2 == ans2){
                res = i;
                break;
            }
        }
        if(res != -1){
            cout << res << "\n";
            continue;
        }
        ans1 = 0,ans2 = 0;
        for(int i=1,j=0,h=1;i<=n;i++){
            ans1 = ans1*P1+val[h];
            ans2 = ans2*P2+val[h];
            j++;
            if(j == k) j = 0,h ^= 1;
        }
        res = -1;
        for(int i=1;i<=n;i++){
            ull sum1 = 0,sum2 = 0,sum3 = 0;
            sum1 = suf1[i+1]*pw1[i]+pre1[i];
            sum2 = suf2[i+1]*pw2[i]+pre2[i];
            if(sum1 == ans1 && sum2 == ans2){
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
	return 0;
}
