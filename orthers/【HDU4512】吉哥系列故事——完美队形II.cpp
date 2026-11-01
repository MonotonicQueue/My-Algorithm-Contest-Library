#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 1e6+10; 
int n,P[N],ans,mx[N];
int a[N],s[N];
inline void change(){
	int k = 0;
	s[0] = 300; s[++k] = 400;
	for(int i=1;i<=n;i++){
		s[++k] = a[i];
		s[++k] = 400;
	}
	s[++k]= 500;
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
    int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        for(int i=1,len=0;i<=n;i++){
            if(a[i] >= a[i-1]) len++;
            else len = 1;
            mx[i] = len;
        }
        change(); manacher(); ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans,min(P[i]-1,mx[i/2]*2-(s[i] != 400)));
        printf("%d\n",ans);
    }
	
	return 0;
} 