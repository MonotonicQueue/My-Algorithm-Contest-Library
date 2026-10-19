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
const int N = 1e5+10;
int n,m,a[N];
bool chk(){
	for(int i=2;i<=n;i++) if(a[i] != a[i-1]) return false;
	return true;
}
int main(){
	int T = read();
	while(T--){
		n = read();
		for(int i=1;i<=n;i++) a[i] = read();
		if(chk()) cout << "NO\n";
		else{
			cout << "YES\n";
			int pos = 1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i == j) continue;
					if(a[i] == a[j]){
						pos = i;
						break;
					}
				}
			}
			for(int i=1;i<=n;i++)
				if(i == pos) cout << "R";
				else cout << "B";
			cout << "\n";
		}
	}
	return 0;
}
