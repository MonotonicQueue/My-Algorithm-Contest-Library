#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e5+10;
int n,a[N];
bool chk(int x){
    for(int i=x+1;i<=n;i++) if(a[i] < a[i-1]) return false;
    a[0] = a[n];
    for(int i=1;i<x;i++) if(a[i] < a[i-1]) return false;
    return true;
}
int main(){
	int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        int minn = 1e9,pos = 0;
        for(int i=1;i<=n;i++)
            if(a[i] < minn) minn = a[i],pos = i;
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(a[i] == minn){
                if(chk(i)) flag = true;
            }
        }
        puts(flag ? "YES" : "NO");
    }
	return 0;
}

