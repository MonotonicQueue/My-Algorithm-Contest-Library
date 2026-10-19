#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 110;
int n;
int ch[1010][1010][7];
int len[7];
int main(){
	n = read();
    len[0] = 1; ch[1][1][0] = 1;
    for(int i=1;i<=n;i++){
        len[i] = len[i-1]*3;
        for(int x=1;x<=len[i-1];x++)
            for(int y=1;y<=len[i-1];y++){
                ch[x][y][i] = ch[x][y+len[i-1]][i] = ch[x][y+len[i-1]*2][i] = 
                ch[x+len[i-1]][y][i] = ch[x+len[i-1]][y+len[i-1]*2][i] = 
                ch[x+len[i-1]*2][y][i] = ch[x+len[i-1]*2][y+len[i-1]][i] = ch[x+len[i-1]*2][y+len[i-1]*2][i] = ch[x][y][i-1];
            }
    }
    for(int i=1;i<=len[n];i++,puts(""))
        for(int j=1;j<=len[n];j++) putchar(ch[i][j][n] == 1 ? '#' : '.');
	return 0;
}
