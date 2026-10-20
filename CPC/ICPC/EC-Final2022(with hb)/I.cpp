#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1.1e5,M=4.1e5;
inline int read(){
    int x=0,ff=1;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') ff=-1;
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x*ff;
}
int n,m,K,d;
int head[N],to[M],nxt[M],tot;
void add_edge(int x,int y){
    ++tot;
    to[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
int distn[N],distk[N];
int q[N];
void bfs(int s,int dist[]){
    memset(dist,0x3f,sizeof(distn));
    int l=1,r=0;
    q[++r]=s;
    dist[s]=0;
    while(l<=r){
        int x=q[l++];
        for(int i=head[x];i;i=nxt[i]){
            int y=to[i];
            if(dist[y]!=dist[0]) continue;
            dist[y]=dist[x]+1;
            q[++r]=y;
        }
    }
}
LL calc(LL dist){
    ++dist;
    LL tmp=(d+1-(dist-dist/d*d));
    // cerr<<tmp<<endl;
    return (d+1ll)*d/2*((dist)/(d))+(d+tmp)*(d-tmp+1)/2;
}
#define pii pair<LL,int>
#define mk make_pair
LL ans[N];
priority_queue<pii> pq;
LL solve(){
    // LL res=1e18;
    memset(ans,0x3f,sizeof(ans));
    pq.push(mk(0,1));
    while(!pq.empty()){
        int x=pq.top().second;
        LL z=-pq.top().first;
        pq.pop();
        if(ans[x]<=z) continue;
        ans[x]=z;
        for(int i=head[x];i;i=nxt[i]){
            int y=to[i];
            // cerr<<"to:"<<y<<" "<<distk[y]<<endl;
            if(distk[y]>=d){
                ans[n]=min(ans[n],ans[x]+calc(distn[y]));
                // cerr<<"!!!"<<y<<' '<<distn[y]<<' '<<calc(distn[y])<<" "<<ans[x]<<endl;
            }
            else   
                pq.push(mk(-ans[x]-(d-distk[y]),y));
        }
    }
    return ans[n];
}
int main(){
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    n=read(),m=read(),K=read(),d=read();
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    bfs(K,distk);
    bfs(n,distn);
    printf("%lld\n",solve());
    // for(int i=1;i<=n;++i)
    //     printf("%d %d %d %lld\n",i,distk[i],distn[i],ans[i]);
}