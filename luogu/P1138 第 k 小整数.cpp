#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1e4+10;
int a[MAX];
void STOP(){
	cout << "NO RESULT";
	exit(0);
}
int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int s = 1,t = a[1],now = 2;
	while(s != k){
		if(t == a[now]) now++;
		else s++ , t = a[now] , now++;
		if(now >= n) STOP();
	}
	if(a[now] != 0) cout << t;
	else cout << "NO RESULT";
	return 0;
}