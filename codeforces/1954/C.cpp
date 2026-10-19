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
string a,b;
int lena,lenb,pos;
bool chk(){
	if(lena < lenb) return true;
	if(lena > lenb) return false;
	for(int i=lena-1;~i;i--) if(a[i] > b[i]){
		pos = i;
		return false;
	} else if(a[i] < b[i]){
		pos = i;
		return true;
	}
	return false;
}
int main(){
	int T = read();
	while(T--){
		cin >> a >> b;
		reverse(a.begin(),a.end()); reverse(b.begin(),b.end()); 
		lena = a.size(); lenb = b.size();
		pos = min(lena,lenb);
		if(chk()) swap(a,b),swap(lena,lenb);
		for(int i=pos-1;~i;i--) if(a[i] > b[i]) swap(a[i],b[i]);
		reverse(a.begin(),a.end()); reverse(b.begin(),b.end()); 
		cout << a << "\n" << b << "\n";
	}
	return 0;
}
