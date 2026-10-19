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
const int N = 1111111;
int n,sum[N];
char ch[N];
int main(){
    scanf("%s",ch+1);
    n = strlen(ch+1);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i-1]+(ch[i] == '1');
    if(sum[n] == 0){
        cout << "0";
        return 0;
    }
    int ans = n;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            ans = min(ans,sum[i-1]+sum[n]-sum[j]+(j-i+1-(sum[j]-sum[i-1])));
    cout << ans;
    return 0;
}
