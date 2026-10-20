#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1.1e5;
int val[N];
int n,a,b[N];
int main(){
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;++i){
        scanf("%d",&b[i]);
        if(!b[i]){
            val[i]++;
            val[i%n+1]++;
            val[(i+n-2)%n+1]++;
        }
    }
    sort(val+1,val+n+1);
    int ans=3*n;
    for(int i=1;i<=a;++i)
        ans-=val[i];
    printf("%d\n",ans);
}