#include<bits/stdc++.h>
int main(){
	std::string k,c;
	std::cin >> k >> c;
	for(int i=0;i<c.size();i++){
		int t = (k[i%k.size()]&31)-1;
		c[i] = (c[i]&31)-t>0?c[i]-t:c[i]-t+26;
	} std::cout << c; return 0;
}