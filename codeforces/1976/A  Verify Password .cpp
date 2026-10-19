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
int n;
char a[N];
bool chk(){
	for(int i=1;i<=n;i++)
		if(!(a[i] >= 'a' && a[i] <= 'z') && !(a[i] >= '0' && a[i] <= '9')) return false;
	for(int i=1;i<n;i++) if(a[i] >= 'a' && a[i] <= 'z' && a[i+1] >= '0' && a[i+1] <= '9') return false;
	int flag1 = -1,flag2 = -1;
	for(int i=1;i<=n;i++){
		if(a[i] >= 'a' && a[i] <= 'z'){
			if(a[i] >= flag1) flag1 = a[i];
			else return false;
		}
		if(a[i] >= '0' && a[i] <= '9'){
			if(a[i] >= flag2) flag2 = a[i];
			else return false;
		}
	}
	return true;
}
int main(){
	int T = read();
    while(T--){
		n = read();
		for(int i=1;i<=n;i++) cin >> a[i];
		puts(chk() ? "YES" : "NO");
	}
	return 0;
}

