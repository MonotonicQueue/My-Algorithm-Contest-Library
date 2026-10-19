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
const int N = 1e7+10;
int n,m,pre,suf;
char s[N],t[N];
int kmp[N];
int main(){
    n = read(); m = read();
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++)
        if(s[i] == t[i]) pre++;
        else break;
    for(int i=n,j=m;i;i--,j--)
        if(s[i] == t[j]) suf++;
        else break;
    // cout << pre << " " << suf << "\n";
    if(pre+suf < n){
        cout << "0";
        return 0;
    }
    int len = m-n,l = pre+1,r = pre+len;
    for(int i=l+1,j=0;i<=r;i++){
        while(j && t[j+l] != t[i]) j = kmp[j];
        if(t[j+l] == t[i]) j++;
        kmp[i] = j;
    }
    int p = (r-l+1)-kmp[r];
    // cout << p << "\n";
    if(len % p) p = len;
    l = m-suf-len+1,r = pre;
    int lim = min(len,r-l+1);
    ll ans = 0;
    for(int i=p;i<=lim;i+=p)
        if(len % i == 0)
            ans += r-l+1-i+1;
    cout << ans;
	return 0;
}
