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
    int z = read(),zz = read();
    zz += z;
    int x = read(),y = read();
    int xx = read(),yy = read();
    if(x > xx) swap(x,xx);
    if(y > yy) swap(y,yy);
    int Q = read();
    while(Q--){
        int u = read(),v = read(),w = read();
        if(x <= u && u <= xx && y <= v && v <= yy && z <= w && w <= zz) puts("YES");
        else puts("NO");
    }
	return 0;
}