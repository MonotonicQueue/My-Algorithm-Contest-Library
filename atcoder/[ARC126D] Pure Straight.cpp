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
const int N = 210;
int n,k,f[1<<16];
int main(){
    n = read(); k = read();
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for(int i=n;i;i--){
        int x = read()-1;
        for(int j=(1<<k)-1;~j;j--){
            if(!((j >> x) & 1))
                f[j|(1<<x)] = min(f[j|(1<<x)],f[j]+__builtin_popcount(j&(~((1<<x)-1))));
            f[j] += min(__builtin_popcount(j),k-__builtin_popcount(j));
        }
    }
    cout << f[(1<<k)-1];
	return 0;
} 