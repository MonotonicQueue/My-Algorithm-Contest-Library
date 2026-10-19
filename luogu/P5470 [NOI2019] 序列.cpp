#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r;
}
const int N = 2e5+10;
int n,K,L,sum;
int a[N],b[N];
int va[N],vb[N];
ll ans;
priority_queue<pii> A0,B0,A1,B1,AB;
inline void adjust(int i){
	if(!va[i] || !vb[i] || va[i] == i) return ;
	int j = va[i],k = vb[i];
	va[i] = vb[i] = i; sum++;
	vb[j] = k; va[k] = j;
	if(j == k) sum++;
}
int main(){
	int T = read();
	while(T--){
		n = read(); K = read(); L = read();
		for(int i=1;i<=n;i++) a[i] = read();
		for(int i=1;i<=n;i++) b[i] = read();
		ans = 0; sum = K-L;
		while(!A0.empty()) A0.pop();
		while(!A1.empty()) A1.pop();
		while(!B0.empty()) B0.pop();
		while(!B1.empty()) B1.pop();
		while(!AB.empty()) AB.pop();
		for(int i=1;i<=n;i++) va[i] = vb[i] = 0;
		for(int i=1;i<=n;i++){
			A0.push(mk(a[i],i));
			B0.push(mk(b[i],i));
			AB.push(mk(a[i]+b[i],i)); 
		}
		while(K--){
			while(!A0.empty() && va[A0.top().se]) A0.pop();
			while(!A1.empty() && va[A1.top().se]) A1.pop();
			while(!B0.empty() && vb[B0.top().se]) B0.pop();
			while(!B1.empty() && vb[B1.top().se]) B1.pop();
			while(!AB.empty() && (va[AB.top().se] || vb[AB.top().se])) AB.pop();
			if(sum){
				int i = A0.top().se,j = B0.top().se;
				ans += a[i]+b[j];
				va[i] = j; vb[j] = i;
				if(i != j){
					sum--;
					if(!va[j]) A1.push(mk(a[j],j));
					if(!vb[i]) B1.push(mk(b[i],i));
				}
				adjust(i); adjust(j);
				continue;
			}
			ll maxn = 0; int type = 0;
			if(!AB.empty()){
				int i = AB.top().se;
				if(a[i] + b[i] > maxn) maxn = a[i]+b[i],type = 1;
			}
			if(!A1.empty() && !B0.empty()){
				int i = A1.top().se,j = B0.top().se;
				if(a[i] + b[j] > maxn) maxn = a[i]+b[j],type = 2;
			}
			if(!A0.empty() && !B1.empty()){
				int i = A0.top().se,j = B1.top().se;
				if(a[i] + b[j] > maxn) maxn = a[i]+b[j],type = 3;
			}
			ans += maxn; 
			if(type == 1){
				int i = AB.top().se; 
				va[i] = vb[i] = i;
			}else if(type == 2){
				int i = A1.top().se,j = B0.top().se;
				int k = vb[i];
				va[i] = vb[i] = i;
				va[k] = j; vb[j] = k;
				if(j == k) ++sum;
				if(!va[j]) A1.push(mk(a[j],j));
				adjust(j); adjust(k);
			}else{
				int i = A0.top().se,j = B1.top().se;
				int k = va[j];
				va[j] = vb[j] = j;
				va[i] = k; vb[k] = i;
				if(i == k) ++sum;
				if(!vb[i]) B1.push(mk(b[i],i));
				adjust(i); adjust(k);
			}
		}
		cout << ans << "\n";
	}

	
	return 0;
}