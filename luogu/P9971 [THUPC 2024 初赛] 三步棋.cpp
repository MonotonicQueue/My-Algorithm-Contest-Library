#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
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
char s[8][8];
int main(){
    int T = read();
   
    while(T--){
        int cnt = 0;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++) cin >> s[i][j];
        int lx = 5,ly = 5,rx = 1,ry = 1;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                if(s[i][j] == 'o'){
                    lx = min(lx,i); ly = min(ly,j);
                    rx = max(rx,i); ry = max(ry,j);
                    cnt++;
                }
        if(cnt == 1) puts("Away");
        else if(cnt == 2) puts("Far");
        else if(cnt == 3) puts("Away");
        else{
            if((rx-lx+1) == 4 && (ry-ly+1) == 1) puts("Away");
            else if((rx-lx+1) == 1 && (ry-ly+1) == 4) puts("Away");
            else if((rx-lx+1) == 2 && (ry-ly+1) == 2) puts("Away");
            else puts("Far");
        }
    }
    return 0;
}