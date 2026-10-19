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
const int N = 4e6+10;
const int mod = 51123987;
int n,len;
char ch[N],s[N];
inline void change(){
    s[0] = '!';
    s[++len] = '|';
    for(int i=1;i<=n;i++){
        s[++len] = ch[i];
        s[++len] = '|';
    }
    s[++len] = '?';
}
int P[N];
ll sum;
void manacher(){
    int C = 0,R = 0;
    for(int i=1;i<=len;i++){
        if(P[i] <= R) P[i] = min(P[2*C-i],R-i+1);
        else P[i] = 1;
        while(s[i+P[i]] == s[i-P[i]]) P[i]++;
        if(i+P[i]-1 > R) R = i+P[i]-1,C = i;
    }
    for(int i=1;i<=len;i++){
        sum += P[i]/2;
        P[i]--;
    }
    sum %= mod;
}
ll f[N],g[N];
int main(){
    n = read();
    scanf("%s",ch+1);
    change(); manacher();
    for(int i=2;i<=len-1;i++){
        if(i & 1){
            f[i/2-P[i]/2+1]++;
            f[i/2+1]--;
            g[i/2+1]++;
            g[i/2+P[i]/2+1]--;
        }else{
            f[i/2-P[i]/2]++;
            f[i/2+1]--;
            g[i/2]++;
            g[i/2+P[i]/2+1]--;
        }
    }
    for(int i=1;i<=n;i++) (f[i] += f[i-1]) %= mod;
    for(int i=1;i<=n;i++) (g[i] += g[i-1]) %= mod;
    for(int i=1;i<=n;i++) (g[i] += g[i-1]) %= mod;
    sum = sum*(sum-1)/2%mod;
    for(int i=1;i<n;i++)
        sum = (sum-g[i]*f[i+1]%mod+mod)%mod;
    cout << sum;
	return 0;
} 
/*
5
aaaaa
*/