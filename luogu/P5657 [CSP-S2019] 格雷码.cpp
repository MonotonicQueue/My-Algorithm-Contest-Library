#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
	ull n,k;
	cin >> n >> k;
	k^=k>>1;
	while(~--n) cout << (k>>n&1);
	return 0;
}

