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
const int N = 5e5+10;
int n,m;
ll a[N],b[N],suma[N][2],sumb[N][2];
ll cnta[N],cntb[N];
int main(){
	int T = read();
    while(T--){
        n = read(); m = read();
		// cout << n << " " << m << "\n";
        for(int i=1;i<=n+m+1;i++) a[i] = read();
		for(int i=1;i<=n+m+1;i++) b[i] = read();
		// for(int i=1;i<=n+m+1;i++) cout << a[i] << " "<< b[i] << "\n";
		for(int i=1;i<=n+m+1;i++){
			suma[i][0] = suma[i-1][0]; suma[i][1] = suma[i-1][1];
			sumb[i][0] = sumb[i-1][0]; sumb[i][1] = sumb[i-1][1];
			cnta[i] = cnta[i-1];
			cntb[i] = cntb[i-1];
			if(a[i] > b[i]) suma[i][0] += a[i],sumb[i][0] += b[i],cnta[i]++;
			else suma[i][1] += a[i],sumb[i][1] += b[i],cntb[i]++;
		}
		for(int i=1;i<=n+m+1;i++){
			if(cnta[n+m+1]-(a[i]>b[i]) >= n){
				int l = 0,r = n+m+1,pos = -1;
				while(l <= r){
					int mid = (l+r)>>1;
					if(mid >= i){
						if(cnta[mid]-(a[i]>b[i]) >= n) pos = mid,r = mid-1;
						else l = mid+1;
					}else{
						if(cnta[mid] >= n) pos = mid,r = mid-1;
						else l = mid+1;
					}
				}
				// cout << pos << "\n";
				ll res = 0;
				if(a[i] > b[i]){
					if(pos >= i) res = a[i];
					else res = b[i];
				}else res = b[i];
				cout << suma[pos][0]+sumb[n+m+1][0]-sumb[pos][0]+sumb[n+m+1][1]-res << " ";
			}else{
				int l = 0,r = n+m+1,pos = -1;
				while(l <= r){
					int mid = (l+r)>>1;
					if(mid >= i){
						if(cntb[mid]-(a[i]<b[i]) >= m) pos = mid,r = mid-1;
						else l = mid+1;
					}else{
						if(cntb[mid] >= m) pos = mid,r = mid-1;
						else l = mid+1;
					}
				}
				ll res = 0;
				if(a[i] < b[i]){
					if(pos >= i) res = b[i];
					else res = a[i];
				}else res = a[i];
				// cout << "0 ";
				cout << suma[n+m+1][0]+sumb[pos][1]+suma[n+m+1][1]-suma[pos][1]-res << " ";
			}
		}
		cout << "\n";
    }
	return 0;
}