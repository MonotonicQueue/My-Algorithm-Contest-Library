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
const int N = 2e5+10;
const ull B = 13331;
int n,a[N];
int lst[N],nxt[N],pos[N];
char s[N];
void solve(){
    scanf("%s",s+1);
    n = strlen(s+1);
    int cnt2 = 0,cnt0 = 0;
    pos[n+1] = 0;
    for(int i=n;i;i--){
        cnt2 += s[i] == '2';
        cnt0 += s[i] == '0';
        a[i] = s[i]-'0';
    }
    auto work = [&](int x){
        ull res = 0;
        for(int i=1;i<n;i++) res = res*B+1;
        cout << x << " " << res << "\n";
    };
    auto calc = [&](int x,int y){
        if(x == 0 && y == 0) return 0;
        if(x == 0 || y == 0) return 1;
        if(x == 1) return y;
        if(y == 1) return x;
        return 1;
    };
    if(cnt0 == n){
        return work(0);
    }
    if(cnt0 == 0){
        if(cnt2 & 1) return work(2);
        return work(1);
    }
    int pos = 0;
    for(int i=n;i;i--)
        if(s[i] == '0'){pos = i; break;}
    if(cnt0 == 1){
        if(s[pos-1] == '2' && s[pos+1] == '2'
         && cnt2 == 2) return work(2);
    }
    cout << "1 ";
    for(int i=1;i<=n;i++){
        lst[i] = i-1;
        nxt[i] = i+1;
    }
    nxt[0] = 1; lst[n+1] = n;
    int T = n-1;
    ull res = 0;
    while(T--){
        for(int i=nxt[0],j=1;nxt[i]!=n+1;i=nxt[i],j++){
            int nowcnt0 = cnt0,nowcnt2 = cnt2;
            nowcnt0 -= (a[i] == 0)+(a[nxt[i]] == 0);
            nowcnt2 -= (a[i] == 2)+(a[nxt[i]] == 2);
            int now = calc(a[i],a[nxt[i]]);
            nowcnt0 += now == 0; nowcnt2 += now == 2;
            int anxt = a[nxt[i]],ai = a[i];
            a[i] = a[nxt[i]] = now; 
            auto chk = [&](){
                if(nowcnt0 >= 2) return true;
                if(nowcnt0 == 1){
                    if(nowcnt2 != 2) return true;
                    if(now == 0) return true;
                    int x = pos;
                    if(a[lst[x]] == 2 && a[nxt[x]] == 2) return false;
                    return true;
                }
                if(nowcnt2 & 1) return false;
                return true;
            };
            if(!chk()) a[i] = ai,a[nxt[i]] = anxt;
            else{
                res = res*B+j;
                cnt0 = nowcnt0; cnt2 = nowcnt2;
                nxt[lst[i]] = nxt[i];
                lst[nxt[i]] = lst[i];
                break;
            }
        }
    }
    cout << res << "\n";
}
int main(){
	int T = read();
    while(T--) solve();
    return 0;
}

