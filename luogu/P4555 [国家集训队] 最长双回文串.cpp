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
int l[N],r[N];
//l_i表示以i结尾的子串的最长回文长度
//r_i表示以i开头的子串的最长回文长度
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
		l[i+P[i]-1] = max(l[i+P[i]-1],P[i]-1);
		r[i-P[i]+1] = max(r[i-P[i]+1],P[i]-1);
	}
}
int main(){
	scanf("%s",a+1); n = strlen(a+1);
	change(); manacher();
	for(int i=n-1;i>=1;i-=2) l[i] = max(l[i],l[i+2]-2);
	for(int i=3;i<n;i+=2) r[i] = max(r[i],r[i-2]-2);
	for(int i=1;i<n;i+=2) if(l[i]&&r[i]) ans = max(ans,l[i]+r[i]);
	printf("%d",ans); 
	return 0;
} 