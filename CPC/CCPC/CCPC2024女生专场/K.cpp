#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
ll read(){
    ll X = 0 ,r = 1;
    char ch = getchar();
    while(!isdigit(ch) && ch != '-') ch = getchar();
    if(ch == '-') r = -1,ch = getchar();
    while(isdigit(ch)) X = X*10+ch-'0',ch = getchar();
    return X*r;
}
const int N = 510;
int n,m,p,q,id;
int s1,s2,s3;
string xiaokai = "crazyzhk";
string s[N];
struct node{
    int a[3],b[3],rk;
    int sa,sb,flag;
}a[N];
int pos[N];
int r1[N],r2[N],rak[N];
int t[N];
bool cmpa(int x,int y){
    if(a[x].sa != a[y].sa) return a[x].sa > a[y].sa;
    if(a[x].a[0] != a[y].a[0]) return a[x].a[0] > a[y].a[0];
    return a[x].rk < a[y].rk;
}
bool cmpb(int x,int y){
    if(a[x].sb != a[y].sb) return a[x].sb > a[y].sb;
    if(a[x].b[0] != a[y].b[0]) return a[x].b[0] > a[y].b[0];
    return a[x].rk < a[y].rk;
}int score[N];
bool cmp(int x,int y){
    if(score[x] != score[y]) return score[x] > score[y];
    if(a[x].sb+a[x].sa != a[y].sb+a[y].sa) return a[x].sb+a[x].sa > a[y].sb+a[y].sa;
    if(a[x].b[0]+a[x].a[0] != a[y].b[0]+a[y].a[0]) return a[x].b[0]+a[x].a[0] > a[y].b[0]+a[y].a[0];
    return a[x].rk < a[y].rk;
}

bool chk(){
    for(int i=1;i<=n;i++) r1[i] = r2[i] = i;
    for(int i=1;i<=n;i++){
        a[i].sa = a[i].sb = 0;
        for(int j=0;j<=2;j++){
            a[i].sa += a[i].a[j];
            a[i].sb += a[i].b[j];
        }
    }
    sort(r1+1,r1+1+n,cmpa);
    sort(r2+1,r2+1+n,cmpb);
    for(int i=1;i<=n;i++) score[i] = 0;
    s1 = 0.15*n; s2 = 0.25*n; s3 = 0.35*n;
    for(int i=0;i<=100;i++) t[i] = 0;
    for(int i=1;i<=n;i++) t[a[i].a[0]]++;
    for(int i=99;i;i--) t[i] += t[i+1];
    for(int i=1;i<=n;i++){
        int x = r1[i];
        int r = t[a[x].a[0]+1]+1;
        if(s1 && r <= int(n/4)){
            s1--;
            score[x] += 15;
        }else if(s2 && r <= int(n*45/100)){
            s2--;
            score[x] += 10;
        }else if(s3 && r <= int(n*75/100)){
            s3--;
            score[x] += 5;
        }
    }
    s1 = 0.15*n; s2 = 0.25*n; s3 = 0.35*n;
    for(int i=0;i<=100;i++) t[i] = 0;
    for(int i=1;i<=n;i++) t[a[i].b[0]]++;
    for(int i=99;i;i--) t[i] += t[i+1];
    for(int i=1;i<=n;i++){
        int x = r2[i];
        int r = t[a[x].b[0]+1]+1;
        if(s1 && r <= int(n/4)){
            s1--;
            score[x] += 15;
        }else if(s2 && r <= int(n*45/100)){
            s2--;
            score[x] += 10;
        }else if(s3 && r <= int(n*75/100)){
            s3--;
            score[x] += 5;
        }
    }
    for(int i=1;i<=n;i++) rak[i] = i;
    sort(rak+1,rak+1+n,cmp);
    for(int i=1;i<=m;i++)
        if(rak[i] == id) return true;
    return false;
}
int main(){
    n = read();
    for(int i=1;i<=n;i++){
        cin >> s[i];
        for(int j=0;j<=2;j++) a[i].a[j] = read(),a[i].sa += a[i].a[j];
        for(int j=0;j<=2;j++) a[i].b[j] = read(),a[i].sb += a[i].b[j];
        if(s[i] == "crazyzhk") a[i].flag = true,id = i;
    }
    m = read(); p = read(); q = read();
    for(int i=1;i<=n;i++) pos[i] = i;
    sort(pos+1,pos+1+n,[](int x,int y){return s[x] < s[y];});
    for(int i=1;i<=n;i++) a[pos[i]].rk = i;
    int ans = 1e9;
    // {
    //     a[id].a[0] += 26; a[id].b[0] += 25;
    //     cout << chk() << "\n";
    // }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(a[id].a[0]+i <= 100 && a[id].b[0]+j <= 100){
                a[id].a[0] += i; a[id].b[0] += j;
                // a[ps].sa += i; a[ps].sb += j;
                if(chk()){
                    // cout << i << " " << j << "\n";
                    ans = min(ans,i*p+j*q);
                }
                a[id].a[0] -= i; a[id].b[0] -= j;
                // a[ps].sa -= i; a[ps].sb -= j;
            }
        }
    }
    if(ans == 1e9) puts("Surely next time");
    else cout << ans;
    

	return 0;
}