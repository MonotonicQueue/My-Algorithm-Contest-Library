#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-'){ch = getchar(); r = -1;}
    while(isdigit(ch)){
    	X = X*10+ch-'0';
    	ch = getchar();
	}
	return X*r;
}
const int N = 4100;
int n,t,pos[N];
vector<int>v[N];
int main(){
	n = read(); t = read();
	for(int i=1;i<=n;i++){
		v[i].push_back(i);
		for(int j=1;j<=n;j++){
			if(i+j <= n) v[i].push_back(i+j);
			else break;
			if(i-j >  0) v[i].push_back(i-j);
			else break;
		}
		pos[v[i].size()] = i;
	}
	for(int i=1;i<=n;i++,puts("")){
		int x = pos[i];
		for(int j=0;j<i;j++)
			cout << v[x][j] << " ";
	}
	return 0;
}