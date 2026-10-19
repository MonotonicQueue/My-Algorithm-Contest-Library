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
int main(){
    int x = read(),y = read();
    cout << y << "\n";
    for(int i=1;i<=(x+y)/2;i++) printf("1 ");
    for(int i=1;i<=y-(x+y)/2;i++) printf("-1 ");
    return 0;
}