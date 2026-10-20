#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
ll read(){
	ll X = 0,r = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') r = -1,ch = getchar();
	while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
	return X*r; 
}
const int N = 410;
const int T = 5e4+10;
int n,m;
char a[N][N],b[N][N];
struct Opt{
    int op,u,v,d,r,l,o;
}t[T];
void rotate(int l,int r,int L,int R,int c){
    // cout << l << " " << r << " " << L << " " << R << " " << c << "\n";
    c = (4-c)%4;
    while(c--){
        swap(l,L); L = n-L+1;
        swap(r,R); R = n-R+1;
        if(l > r) swap(l,r);
        if(L > R) swap(L,R);
    }
    
    // cout << l << " " << r << " " << L << " " << R << "\n";
    
    //将 l <= x <= r,L <= y <= R 顺时针旋转 90
    int n = r-l+1;
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++)
            b[(j-L+1)+l-1][n-(i-l+1)+1+L-1] = a[i][j];
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++) a[i][j] = b[i][j];
}
void rev0(int l,int r,int L,int R,int c){
    //上下翻转
    c = (4-c)%4;
    while(c--){
        swap(l,L); L = n-L+1;
        swap(r,R); R = n-R+1;
        if(l > r) swap(l,r);
        if(L > R) swap(L,R);
    }
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++)
            b[l+r-i][j] = a[i][j];
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++) a[i][j] = b[i][j];
}
void rev1(int l,int r,int L,int R,int c){
    //左右翻转
    c = (4-c)%4;
    while(c--){
        swap(l,L); L = n-L+1;
        swap(r,R); R = n-R+1;
        if(l > r) swap(l,r);
        if(L > R) swap(L,R);
    }
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++)
            b[i][R+L-j] = a[i][j];
    for(int i=l;i<=r;i++)
        for(int j=L;j<=R;j++) a[i][j] = b[i][j];
}
int main(){
    // freopen("3.in","r",stdin);
    // freopen("decode.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin >> a[i][j];
    m = read(); m = read();
    for(int i=1;i<=m;i++){
        t[i].op = read();
        if(t[i].op == 1){
            t[i].u = read(); t[i].v = read();
            t[i].l = read(); t[i].d = read();
            t[i].r = read();
        }else{
            t[i].u = read(); t[i].d = read();
            t[i].l = read(); t[i].r = read();
            t[i].o = read();
        }
    }
    int cnt = 0;
    for(int i=m;i;i--){
        if(t[i].op == 1){
            cnt += t[i].r;
            cnt %= 4;
            int d = t[i].d/90; d = (4-d)%4;
            while(d--){
                rotate(t[i].u,t[i].u+t[i].l-1,t[i].v,t[i].v+t[i].l-1,cnt);
            }
            
        }else{
            if((t[i].o == 1 && cnt % 2 == 0) || (t[i].o == -1 && cnt % 2 == 1)){
                rev0(t[i].u,t[i].d,t[i].l,t[i].r,cnt);
            }else{
                rev1(t[i].u,t[i].d,t[i].l,t[i].r,cnt);
            }
        }
        // for(int i=1;i<=n;i++,cerr<<"\n")
        //     for(int j=1;j<=n;j++) cerr << a[i][j];
        // cerr << "\n";
    }
    while(cnt--) rotate(1,n,1,n,0);
    // for(int i=1;i<=n;i++,puts(""))
    //     for(int j=1;j<=n;j++) cout << a[i][j];
    int s = 0,t = 0;
    for(int i=1;i<=n;i++)
        if(a[i][1] != '?') s = i;
    for(int i=1;i<=n;i++)
        if(a[1][i] != '?') t = i;
    cout << s << " " << t << "\n";
    for(int i=1;i<=s;i++,puts(""))
        for(int j=1;j<=t;j++) cout << a[i][j];
	return 0;
}
/*
C???
1Nk?
??F?
??C?

C???
kN1?
F???
??C?

????
?kFC
?N??
C1??

?N??
?kFC
????
C1??

C???
kN1?
F???
??C?

*/