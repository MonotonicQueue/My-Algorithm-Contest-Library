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
const int N = 1010;
const int M = 2e6+10;
int n,m,k,a[M];
struct OPT{int op,x,y;};
vector<OPT> ans;
int stk[N][3],p[N];
int pos,cnt[N];
void clear(){
    ans.clear();
    for(int i=1;i<=n;i++) stk[i][0] = stk[i][1] = stk[i][2] = 0;
    for(int i=1;i<=k;i++) p[i] = 0,cnt[i] = 0;
}
set<int> s;
int work(int st){
    auto reset = [&](int l,int r){
        for(int i=l;i<=r;i++) cnt[a[i]] = 0;
    };
    for(int i=st+1;i<=m;i++){
        cnt[a[i]] ^= 1;
        if(a[i] == a[st]){
            ans.push_back(OPT{1,pos,0});
            for(int j=st+1;j<i;j++){
                if(p[a[j]]){
                    assert(stk[p[a[j]]][1] == a[j]);
                    ans.push_back(OPT{1,p[a[j]],0});
                    stk[p[a[j]]][1] = 0;
                    s.insert(p[a[j]]);
                    p[a[j]] = 0;
                }else{
                    int x = *s.begin();
                    s.erase(x);
                    assert(stk[x][0] != 0);
                    ans.push_back(OPT{1,x,0});
                    stk[x][1] = a[j];
                    p[a[j]] = x;
                }
            }
            ans.push_back(OPT{1,pos,0});
            reset(st,i);
            return i;
        }
        int x = p[a[i]];
        if(stk[x][0] == a[i]){
            int y = stk[x][1];
            if(cnt[y]){
                s.erase(x);
                stk[pos][0] = a[st];
                ans.push_back(OPT{1,pos,0});
                p[a[st]] = pos;
                s.insert(pos);
                pos = x;
                p[a[i]] = p[y] = 0;
                stk[x][0] = stk[x][1] = 0;
                for(int j=st+1;j<=i;j++){
                    if(a[j] == a[i] || a[j] == y){
                        ans.push_back(OPT{1,x,0});
                        continue;
                    }
                    if(p[a[j]]){
                        ans.push_back(OPT{1,p[a[j]],0});
                        stk[p[a[j]]][1] = 0;
                        s.insert(p[a[j]]);
                        p[a[j]] = 0;              
                    }else{
                        int x = *s.begin();
                        s.erase(x);
                        assert(stk[x][0] != 0);
                        ans.push_back(OPT{1,x,0});
                        stk[x][1] = a[j];
                        p[a[j]] = x;
                    }
                }
                reset(st,i);
                return i;
            }else{
                stk[x][0] = stk[x][1]; stk[x][1] = a[st];
                p[a[i]] = 0; p[a[st]] = x;
                ans.push_back(OPT{1,x,0});
                for(int j=st+1;j<i;j++){
                    if(a[j] == y){
                        ans.push_back(OPT{1,pos,0});
                        continue;
                    }
                    if(p[a[j]]){
                        ans.push_back(OPT{1,p[a[j]],0});
                        stk[p[a[j]]][1] = 0;
                        s.insert(p[a[j]]);
                        p[a[j]] = 0;              
                    }else{
                        int x = *s.begin();
                        s.erase(x);
                        assert(stk[x][0] != 0);
                        ans.push_back(OPT{1,x,0});
                        stk[x][1] = a[j];
                        p[a[j]] = x;
                    }
                }
                ans.push_back(OPT{1,pos,0});
                ans.push_back(OPT{2,x,pos});
                reset(st,i);
                return i;
            }
        }
    }
}
void solve(){
    pos = n;
    s.clear();
    for(int i=1;i<n;i++) s.insert(i);
    for(int i=1;i<=m;i++){
        if(p[a[i]]){
            int x = p[a[i]];
            if(stk[x][1] == a[i]){
                ans.push_back(OPT{1,x,0});
                stk[x][1] = 0;
                p[a[i]] = 0;
                s.insert(x);
            }else{
                assert(stk[x][0] == a[i]);
                if(stk[x][1]){
                    ans.push_back(OPT{1,pos,0});
                    ans.push_back(OPT{2,x,pos});
                    stk[x][0] = stk[x][1];
                    stk[x][1] = 0;
                    if(stk[x][0]) s.insert(x);
                    p[a[i]] = 0;
                }else{
                    ans.push_back(OPT{1,x,0});
                    stk[x][0] = 0;
                    p[a[i]] = 0;
                }
            }
        }else{
            if(!s.empty()){
                int x = *s.begin();
                assert(stk[x][1] == 0);
                p[a[i]] = x;
                ans.push_back(OPT{1,x,0});
                if(!stk[x][0]){
                    stk[x][0] = a[i];
                }else{
                    stk[x][1] = a[i];
                    s.erase(x);
                }
            }else{
                i = work(i);
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto it : ans){
        if(it.op == 1) cout << it.op << " " << it.x << "\n";
        else cout << it.op << " " << it.x << " " << it.y << "\n";
    }
}
signed main(){
    // freopen("meow.in","r",stdin);
    // freopen("meow.out","w",stdout);
    int T = read();
    while(T--){
        n = read(); m = read(); k = read();
        for(int i=1;i<=m;i++) a[i] = read();
        clear(); solve();
    }
    return 0;
}