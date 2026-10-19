#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 2e5+10;
long long read(){
	long long f=1,r=0;
	char ch;
	do ch=getchar(); while(!isdigit(ch) && ch!='-');
	if(ch=='-') f=-1,ch=getchar();
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	return r*f;
}
void write(long long X) {
	if(X < 0) putchar('-'),X=-X;
    if(X>9) write(X/10); 
    putchar(X%10+'0');
}
ll n,m,ans;
ll fa[5005];
struct rec{
	ll x,y,z;
}edge[MAX];
bool operator <(rec a,rec b){
	return a.z < b.z;
}
inline void init(){
	for(int i=1;i<=n;i++)
		fa[i] = i;
}
ll get(ll x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
inline bool chk(){
	for(int i=2;i<=n;i++)
		if(get(i) != get(1))
			return false;
	return true;
}
int main(){
	n = read(); m = read();
	for(int i=1;i<=m;i++){
		edge[i].x = read();
		edge[i].y = read();
		edge[i].z = read();
	}
	sort(edge+1,edge+1+m);
	init();
	for(int i=1;i<=m;i++){
		ll x = get(edge[i].x);
		ll y = get(edge[i].y);
		if(x == y) continue;
		fa[x] = y;
		ans += edge[i].z;
	}
	if(chk()) write(ans);
	else puts("orz");
	return 0;
}