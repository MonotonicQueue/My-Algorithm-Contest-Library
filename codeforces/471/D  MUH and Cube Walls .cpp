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
const int N = 2e5+10;
int n,w;
int a[N],b[N],kmp[N];
int main(){
	n = read(); w = read();
    for(int i=1;i<=n;i++) a[i] = read();
    for(int i=1;i<=w;i++) b[i] = read();
    if(w == 1){
        cout << n << "\n";
        return 0;
    }
    n--; w--;
    for(int i=1;i<=n;i++) a[i] = a[i+1]-a[i];
    for(int i=1;i<=w;i++) b[i] = b[i+1]-b[i];
    for(int i=2,j=0;i<=w;i++){
        while(j && b[i] != b[j+1]) j = kmp[j];
        if(b[i] == b[j+1]) j++;
        kmp[i] = j;
    }
    int ans = 0;
    for(int i=1,j=0;i<=n;i++){
        while(j && a[i] != b[j+1]) j = kmp[j];
        if(a[i] == b[j+1]) j++;
        if(j == w){
            ans++;
            j = kmp[j];
        }
    }
    cout << ans;
	return 0;
}

