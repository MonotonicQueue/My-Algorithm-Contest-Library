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
const int N = 110;
int n;
char ch[N];
int a[N],b[N];
bool work(int x){
//	for(int i=1;i<=x;i++) cout << a[i] << " ";
//	cout << "\n";
	int cnt = 0;
	for(int i=1;i<=x;i++){
		if(a[i]){
			if(x == 1){
				return true;
			}
			a[i] = -1;
			if(i == 1){
				a[2] ^= 1; a[x] ^= 1;
			}else if(i == x){
				a[x-1] ^= 1; a[1] ^= 1;
			}else{
				a[i-1] ^= 1; a[i+1] ^= 1;
			}
			for(int j=1;j<=x;j++) if(i != j) b[++cnt] = a[j];
			for(int j=1;j<=x;j++) a[j] = b[j];
			return true;
		}
	}
	return false;
}
int main(){
	int T = read();
	while(T--){
		n = read();
		cin >> ch+1;
		for(int i=1;i<=n;i++) a[i] = ch[i] == 'U';
		int len = n;
		while(work(len)){
			len--;
//			for(int i=1;i<=len;i++) cout << a[i] << " ";
//			cout << "\n";
		}
//		cout << len << "\n";
		if((n-len) & 1) puts("YES");
		else puts("NO");
	}
	return 0;
}