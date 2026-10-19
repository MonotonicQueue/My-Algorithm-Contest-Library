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
int x;
int a[50],tot;
int main(){
	int T = read();
    while(T--){
        x = read();
		int n = 0;
		for(int i=0;i<=30;i++){
			a[i] = (x>>i) & 1;
			if(a[i]) n = i;
		}
		for(int i=0;i<n;i++){
			if(a[i] && a[i+1]){
				int j = i;
				for(j;j<=n&&a[j];j++);
				a[j] = 1;
				a[i] = -1;
				for(int k=i+1;k<j;k++) a[k] = 0;
			}
		}
		if(a[n+1]) n++;
		cout << n+1 << "\n";
		for(int i=0;i<=n;i++) cout << a[i] << " ";
		cout << "\n";
    }
	return 0;
}

