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
int n,a[N],b[N];
int main(){
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1;i<=n;i++) b[i] = read();
        int x = 0,y = 0;
        int v = 0,vv = 0;
        for(int i=1;i<=n;i++){
            if(a[i] > b[i]) x += a[i];
            else if(a[i] < b[i]) y += b[i];
            else{
                if(a[i] == 1) v++;
                else if(a[i] == -1)vv++;
            }
        }
        while(v--){
            if(x > y) y++;
            else x++;
        }
        while(vv--){
            if(x > y) x--;
            else y--;
        }
        cout << min(x,y) << "\n";
    }
	return 0;
}
