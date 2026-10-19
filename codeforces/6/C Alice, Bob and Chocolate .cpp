#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;
int n,m;
int t[MAX];
int sum[MAX];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)	
		cin >> t[i];
	int head = 1,tail = n;
	int t1 = 0,t2 = 0;
	while(head <= tail){
		if(t1 <= t2){
			t1+=t[head++];
		}
		else{
			t2+=t[tail--];
		}
	}
	cout << head-1 << " " << n-tail;
	return 0;
}