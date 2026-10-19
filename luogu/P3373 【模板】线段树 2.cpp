#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e5+10;
long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
void write(long long X){
	if(X < 0) putchar('-'),X=-X;
    if(X>9) write(X/10); 
    putchar(X%10+'0'); 
}
long long n,m,p;
long long a[MAX],sum[MAX<<5],tag1[MAX<<5],tag2[MAX<<5];
inline void Push_up(int rt){sum[rt] = sum[rt<<1]+sum[rt<<1|1];}
void Build(long long l,long long r,long long rt){
	if(l == r){
		sum[rt] = a[l];
		return;
	}
	tag2[rt] = 1;
	long long mid = (l+r)>>1;
	Build(l,mid,rt<<1);
	Build(mid+1,r,rt<<1|1);
	Push_up(rt);
}
inline void Push_down(long long rt,long long l,long long r){
	//if(!tag1[rt] && tag2[rt] == 1) return;
	long long mid = (l+r)>>1;
	tag2[rt<<1] = tag2[rt]*tag2[rt<<1]%p;
	tag2[rt<<1|1] = tag2[rt]*tag2[rt<<1|1]%p;
	tag1[rt<<1] = (tag1[rt<<1]*tag2[rt]+tag1[rt])%p;
	tag1[rt<<1|1] = (tag1[rt<<1|1]*tag2[rt]+tag1[rt])%p;
	sum[rt<<1] = (sum[rt<<1]*tag2[rt]+tag1[rt]*(mid-l+1))%p;
	sum[rt<<1|1] = (sum[rt<<1|1]*tag2[rt]+tag1[rt]*(r-mid))%p;
	tag1[rt] = 0;
	tag2[rt] = 1;
}
void Update1(long long nl,long long nr,long long c,long long l,long long r,long long rt){
	if(l >= nl && r <= nr){
		sum[rt] += c*(r-l+1);
		sum[rt] %= p;
		tag1[rt] += c;
		return;
	}
	int mid = (l+r)>>1;
	Push_down(rt,l,r);
	if(mid >= nl) Update1(nl,nr,c,l,mid,rt<<1);
	if(mid < nr) Update1(nl,nr,c,mid+1,r,rt<<1|1);
	Push_up(rt);
}
void Update2(long long nl,long long nr,long long c,long long l,long long r,long long rt){
	if(l >= nl && r <= nr){
		sum[rt] *= c; sum[rt] %= p;
		tag2[rt] *= c;
		tag1[rt] *= c;
		return;
	}
	int mid = (l+r)>>1;
	Push_down(rt,l,r);
	if(mid >= nl) Update2(nl,nr,c,l,mid,rt<<1);
	if(mid < nr) Update2(nl,nr,c,mid+1,r,rt<<1|1);
	Push_up(rt);
}
long long Query(long long nl,long long nr,long long l,long long r,long long rt){
	if(l >= nl && r <= nr) return sum[rt];
	Push_down(rt,l,r);
	long long mid = (l+r)>>1;
	long long ans = 0;
	if(mid >= nl) ans += Query(nl,nr,l,mid,rt<<1);
	if(mid < nr) ans += Query(nl,nr,mid+1,r,rt<<1|1);
	return ans%p;
}
int main(){
	//freopen("P3373_2.in","r",stdin);
	//freopen("P3373_2.ans","w",stdout);
	n = read(); m = read(); p = read();
	for(int i=1;i<=n;i++)
		a[i] = read();
	Build(1,n,1);
	while(m--){
		int op = read();
		if(op == 1){
			long long x = read(),y = read(),k = read();
			Update2(x,y,k,1,n,1);
		}
		else if(op == 2){
			long long x = read(),y = read(),k = read();
			Update1(x,y,k,1,n,1);
		}
		else{
			long long x = read(),y = read();
			write(Query(x,y,1,n,1));
			puts("");
		}
	}
	return 0;
}