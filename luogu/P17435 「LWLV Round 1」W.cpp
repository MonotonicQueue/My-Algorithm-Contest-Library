#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    if(m >= n*(k-1)){
        cout << (n-1)*(k-1)+(m-(n-1)*(k-1))%k;
    }else{
        cout << m << "\n";
    }
	return 0;
}