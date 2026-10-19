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
int n,a[N];
int cnt[N];
int main(){
    int T = read();
    for(int i=1;i<=200000;i++) cnt[i] = cnt[i/3]+1;
    for(int i=1;i<=200000;i++) cnt[i] += cnt[i-1];
    while(T--){
        int l = read(),r = read();
        cout << cnt[r]-cnt[l-1]+cnt[l]-cnt[l-1] << "\n";
    }
    return 0;
}
