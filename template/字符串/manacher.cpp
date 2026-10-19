#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10; 
int n,P[N],ans;
char a[N],s[N];
inline void change(){
	int k = 0;
	s[0] = '$'; s[++k] = '#';
	for(int i=1;i<=n;i++){
		s[++k] = a[i];
		s[++k] = '#';
	}
	s[++k]= '&';
	n = k;
}
void manacher(){
	int R = 0,C = 0;
	for(int i=1;i<n;i++){
		if(i < R) P[i] = min(P[C*2-i],P[C]+C-i);
		else P[i] = 1;
		while(s[i-P[i]] == s[i+P[i]]) P[i]++;
		if(i+P[i] > R){
			R = i+P[i];
			C = i;
		}
	}
}
int main(){
	scanf("%s",a+1); n = strlen(a+1);
	change(); manacher();
	for(int i=1;i<=n;i++) cout << s[i] << " ";
	cout << "\n";
	for(int i=1;i<=n;i++) cout << P[i] << " ";
	cout << "\n";
	for(int i=1;i<=n;i++) ans = max(ans,P[i]);
	printf("%d",ans-1);
	return 0;
} 
