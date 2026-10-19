#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define all(x) x.begin(),x.end()
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 5e4+10;
int m,k,a[N];
char s[N],t[4] = {'A','C','G','T'};
ll R,f[N][12][4];
int main(){
	m = read(); k = read(); R = read();
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
		if(s[i] == 'A') a[i] = 0;
		else if(s[i] == 'C') a[i] = 1;
		else if(s[i] == 'G') a[i] = 2;
		else if(s[i] == 'T') a[i] = 3;
		else a[i] = 4;
	for(int i=1;i<=k;i++) f[m+1][i][3] = 1;
	for(int i=m;i;i--){
		for(int v=0;v<=3;v++){
			if(a[i] != 4 && a[i] != v) continue;
			for(int j=1;j<=k;j++)
				for(int h=0;h<=3;h++)
					if(v <= h) f[i][j][v] += f[i+1][j][h];
					else f[i][j][v] += f[i+1][j-1][h];
		}
	}
	int lst = 0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=3;j++)
			if(f[i][k-(lst > j)][j] < R) R -= f[i][k-(lst > j)][j];
			else{
				k -= lst > j; lst = j;
				cout << t[j];
				break;
			}
	}
    return 0;
}