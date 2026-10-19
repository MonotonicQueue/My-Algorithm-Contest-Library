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
int a,b,c,d;
int main(){
    a = read(); b = read(); c = read(); d = read();
    if((a+b)+c == d || (a+b)-c == d || (a+b)*c == d ||
    (a-b)+c == d || (a-b)-c == d || (a-b)*c == d || (a*b)+c == d || (a*b)-c == d || (a*b)*c == d )
        puts("Yes");
    else puts("No");
    return 0;
}