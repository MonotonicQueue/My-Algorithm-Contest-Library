#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
int n,m;
int a[N],lst[N],f[N];
multiset<int> s;
int main(){
	n = read(); m = read();
	for(int i=1;i<=n;i++) a[i] = read();
	for(int i=1;i<=m;i++) s.insert(0);
	for(int i=1;i<=n;i++){
		f[i] = *s.begin()+1;
		s.erase(s.find(f[lst[a[i]]]));
		lst[a[i]] = i;
		s.insert(f[i]);
	}
	cout << (*s.begin())+1;
    return 0;
}