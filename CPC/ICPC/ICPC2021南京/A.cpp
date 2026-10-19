#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
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

int main(){
    int n = read(),a = read(),b = read();
    if((a-1) <= (n-a)){
    	for(int i=1;i<n;i++) cout << "U";
		for(int i=1;i<a;i++) cout << "D";
	}else{
		for(int i=1;i<n;i++) cout << "D";
		for(int i=n;i>a;i--) cout << "U";
	}
	if((b-1) <= (n-b)){
    	for(int i=1;i<n;i++) cout << "L";
		for(int i=1;i<b;i++) cout << "R";
	}else{
		for(int i=1;i<n;i++) cout << "R";
		for(int i=n;i>b;i--) cout << "L";
	}
    return 0;
}
