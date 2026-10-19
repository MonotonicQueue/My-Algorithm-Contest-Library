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
const int N = 2e5+10;
int n,q;
char a[N],b[N];
int sum1[N][30],sum2[N][30];
int main(){
    int T = read();
    while(T--){
        n = read(); q = read();
        scanf("%s",a+1);
        scanf("%s",b+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++){
                sum1[i][j] = sum1[i-1][j];
                sum2[i][j] = sum2[i-1][j];
            }
            sum1[i][a[i]-'a']++;
            sum2[i][b[i]-'a']++;
        }
        while(q--){
            int l = read(),r = read();
            int cnt = 0;
            for(int i=0;i<=25;i++)
                cnt += max((sum1[r][i]-sum1[l-1][i])-(sum2[r][i]-sum2[l-1][i]),0);
            printf("%d\n",cnt);
        }
    }
	return 0;
}
