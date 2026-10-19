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
int cnt[N],n = 10;
string s = " codeforces";
int main(){
    ll k = read();
    for(int i=1;i<=n;i++) cnt[i] = 1;
    ll res = 1;
    while(res < k){
        int mn = cnt[1],pos = 1;
        for(int i=2;i<=n;i++){
            if(cnt[i] < mn){
                mn = cnt[i];
                pos = i;
            }
        }
        res /= cnt[pos];
        cnt[pos]++;
        res *= cnt[pos];
    }
    for(int i=1;i<=n;i++)
        while(cnt[i]--) putchar(s[i]);
    return 0;
}