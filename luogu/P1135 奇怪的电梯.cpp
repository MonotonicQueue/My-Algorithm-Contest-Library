#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=210;
int n;
int a[MAX];
int m[MAX];
bool p[MAX];
queue <int> q;
int main(){
	int c,b;
	ios::sync_with_stdio(false);
	cin>>n>>c>>b;
	for(int i=1;i<=n;i++) cin>>m[i];
	if(b==c){
		cout<<"0";
		return 0;
	}
	p[c]=1; a[c]=0;
	q.push(c);
	while(!q.empty()){
		int xx=q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int xxx=xx;
			if(i==0) xxx-=m[xx];
			else xxx+=m[xx];
			if(xxx<1 || xxx>n || p[xxx]) continue;
			q.push(xxx);
			p[xxx]=1;
			a[xxx]=a[xx]+1;
			if(xxx==b){
				cout<<a[xxx];
				return 0;
			}
		}
	}
	cout<<"-1";
	return 0;
}