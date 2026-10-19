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
const int N = 1e5+10;
int n,a[N],b[N];

int main(){
	int T = read();
    while(T--){
        n = read();
        for(int i=1;i<=n;i++) a[i] = read();
        sort(a+1,a+1+n);
		int tot = 0;
		for(int i=2;i<=n;i++)
			if(a[i] % a[1] != 0) b[++tot] = a[i];
		if(!tot) puts("YES");
		else{
			bool flag = 0;
			for(int i=2;i<=tot;i++)
				if(b[i] % b[1] != 0) flag = true;
			if(flag) puts("NO");
			else puts("YEs");
		}
    }
	return 0;
}

