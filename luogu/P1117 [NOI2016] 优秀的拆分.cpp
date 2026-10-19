#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
    ll X = 0,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') ch = getchar(),r = -1;
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 3e4+10;
int n;
char ch[N];
int sa[N],rk1[N],rk2[N],cnt[N],x[N],y[N];
int height1[N],height2[N],LOG2[N];
inline void getsa(){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	int m = 127;
	for(int i=1;i<=m;i++) cnt[i] = 0;
	for(int i=1;i<=n;i++) cnt[x[i] = ch[i]]++;
	for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
	for(int i=n;i>=1;i--) sa[cnt[x[i]]--] = i;
	for(int k=1;k<=n;k*=2){
		int p = 0;
		for(int i=n-k+1;i<=n;i++) y[++p] = i;
		for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;
		for(int i=1;i<=m;i++) cnt[i] = 0;
		for(int i=1;i<=n;i++) cnt[x[i]]++;
		for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
		for(int i=n;i>=1;i--) sa[cnt[x[y[i]]]--] = y[i];
		p = 1; swap(x,y); x[sa[1]] = 1;
		for(int i=2;i<=n;i++)
			x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p;
		if(p >= n) break;
		m = p;
	}
}
inline void getheight1(){
	for(int i=1;i<=n;i++) rk1[sa[i]] = i,height1[i] = 0;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(rk1[i] == 1) continue;
		if(k) k--;
		int j = sa[rk1[i]-1];
		while(ch[i+k] == ch[j+k]) k++;
		height1[rk1[i]] = k;
	}
}
inline void getheight2(){
	for(int i=1;i<=n;i++) rk2[sa[i]] = i,height2[i] = 0;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(rk2[i] == 1) continue;
		if(k) k--;
		int j = sa[rk2[i]-1];
		while(ch[i+k] == ch[j+k]) k++;
		height2[rk2[i]] = k;
	}
}
int st1[N][16],st2[N][16];
void build1(){
	memset(st1,0x3f,sizeof(st1));
	for(int i=1;i<=n;i++) st1[i][0] = height1[i];
	for(int j=1;j<=15;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st1[i][j] = min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
}
int query1(int l,int r){
	int x = min(rk1[l],rk1[r])+1,y = max(rk1[l],rk1[r]);
	int t = LOG2[y-x+1];
	return min(st1[x][t],st1[y-(1<<t)+1][t]);
}
void build2(){
	memset(st2,0x3f,sizeof(st2));
	for(int i=1;i<=n;i++) st2[i][0] = height2[i];
	for(int j=1;j<=15;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st2[i][j] = min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
}
int query2(int l,int r){
	int x = min(rk2[l],rk2[r])+1,y = max(rk2[l],rk2[r]);
	int t = LOG2[y-x+1];
	return min(st2[x][t],st2[y-(1<<t)+1][t]);
}
int f[N],g[N];
int main(){
	for(int i=2;i<=30000;i++) LOG2[i] = LOG2[i>>1]+1;
	int T = read();
	while(T--){ 
		scanf("%s",ch+1);
		n = strlen(ch+1);
		getsa(); getheight1();
		build1();
		reverse(ch+1,ch+1+n);
		getsa(); getheight2();
		build2();
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int len=1;len<=n/2;len++)
			for(int i=len,j=i+len;j<=n;i+=len,j+=len){
				int lcp = min(query1(i,j),len),lcs = min(query2(n-i+2,n-j+2),len-1);
				int t = lcp+lcs-len+1;
				if(lcp + lcs >= len){
					g[i-lcs]++; g[i-lcs+t]--;
					f[j+lcp]--; f[j+lcp-t]++;
				}
			}
		for(int i=1;i<=n;i++) f[i] += f[i-1],g[i] += g[i-1];
		ll ans = 0;
		for(int i=1;i<n;i++) ans += 1ll*f[i]*g[i+1];
		printf("%lld\n",ans);
	}
	return 0; 
}
