#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const int B = 7000,M = N/B+10;
int n,m,Q,a[N],b[N],pa[N],pb[N];
int pos[N],L[N],R[N],tot;
vector<int> G[N];
bitset<N> c[N],ba[M],bb[M],now;
void clear(){
    for(int i=1;i<=n;i++){
        c[i].reset();
        G[i].clear();
    }
}
void solve(){
    n = read(); m = read(); Q = read();
    clear();
    for(int i=1;i<=m;i++){
        int u = read(),v = read();
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) a[i] = read(),pa[a[i]] = i;
    for(int i=1;i<=n;i++) b[i] = read(),pb[b[i]] = i;
    for(int i=n;i;i--){
        c[i][i] = 1;
        for(int j : G[i]) c[i] |= c[j];
    }
    tot = (n-1)/B+1;
    for(int i=1;i<=n;i++) pos[i] = (i-1)/B+1;
    for(int i=1;i<=tot;i++){
        L[i] = (i-1)*B+1;
        R[i] = i*B;
    }
    R[tot] = n;
    for(int i=1;i<=tot;i++)
        ba[i].reset(),bb[i].reset();
    for(int i=1;i<=n;i++){
        ba[pos[a[i]]][i] = 1;
        bb[pos[b[i]]][i] = 1;
    }
    while(Q--){
        int op = read();
        if(op == 1){
            int x = read(),y = read();
            ba[pos[a[x]]][x] = 0,ba[pos[a[y]]][y] = 0;
            swap(a[x],a[y]); pa[a[x]] = x,pa[a[y]] = y;
            ba[pos[a[x]]][x] = 1,ba[pos[a[y]]][y] = 1;
        }else if(op == 2){
            int x = read(),y = read();
            bb[pos[b[x]]][x] = 0,bb[pos[b[y]]][y] = 0;
            swap(b[x],b[y]); pb[b[x]] = x,pb[b[y]] = y;
            bb[pos[b[x]]][x] = 1,bb[pos[b[y]]][y] = 1;
        }else{
            int x = read(),l = read(),r = read();
            now.reset();
            if(pos[l] == pos[r]){
                for(int i=l;i<=r;i++) now[pa[i]] = 1;
            }else{
                for(int i=l;i<=R[pos[l]];i++) now[pa[i]] = 1;
                for(int i=pos[l]+1;i<=pos[r]-1;i++) now |= ba[i];
                for(int i=L[pos[r]];i<=r;i++) now[pa[i]] = 1;
            }
            now &= c[x];
            int y = 0;
            for(int i=tot;i;i--)
                if((now&bb[i]).any()){
                    y = i;
                    break;
                }
            if(!y) cout << "0\n";
            else{
                for(int i=R[y];i>=L[y];i--)
                    if(now[pb[i]]){
                        cout << i << "\n";
                        break;
                    }
            }
        }
    }
}
int main(){
    int c = read(),T = read();
    while(T--) solve();
	return 0;
}