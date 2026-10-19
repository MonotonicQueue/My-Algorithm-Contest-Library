#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
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
struct SA{
    int n;
    string ch;
    int sa[N],rk[N],height[N],x[N],y[N],cnt[N];
    void getsa(){
        int m = 127;
        for(int i=1;i<=n;i++) cnt[x[i] = ch[i]]++;
        for(int i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[x[i]]--] = i;
        for(int k=1;k<=n;k*=2){
            int p = 0;
            for(int i=n-k+1;i<=n;i++) y[++p] = i;
            for(int i=1;i<=n;i++) if(sa[i] > k) y[++p] = sa[i]-k;
            
            for(int i=1;i<=m;i++) cnt[i] = 0;
            for(int i=1;i<=n;i++) cnt[x[i]]++;
            for(int i=2;i<=m;i++) cnt[i] += cnt[i-1];
            for(int i=n;i>=1;i--) sa[cnt[x[y[i]]]--] = y[i];
            swap(x,y); p = 1;
            x[sa[1]] = 1;
            for(int i=2;i<=n;i++)
                x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i]+k] == y[sa[i-1]+k] ? p : ++p;
            m = p;
            if(m >= n) break;
        }
    }
    void getheight(){
        for(int i=1;i<=n;i++) rk[sa[i]] = i;
        int k = 0;
        for(int i=1;i<=n;i++){
            if(rk[i] == 1) continue;
            if(k) k--;
            int j = sa[rk[i]-1];
            while(ch[i+k] == ch[j+k]) k++;
            height[rk[i]] = k;
        }
    }
    void init(string s){
        n = s.size();
        ch = " "+s;
        getsa(); getheight();
    }
    ll getcnt(){
        ll res = 1ll*n*(n-1)/2+n;
        for(int i=2;i<=n;i++) res -= height[i];
        return res;
    }
};
int main(){
	
	return 0;
}




























