#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=130;
inline int read(){
    int x=0,ff=1;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-') ff=-1;
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    return x*ff;
}
int n;
int head[N],to[N*N],nxt[N*N],Mid[N*N],tot;
void add_edge(int x,int y,int z){
    ++tot;
    to[tot]=y;
    nxt[tot]=head[x];
    Mid[tot]=z;
    head[x]=tot;
    // cerr<<"Edge:"<<x<<' '<<y<<endl;
}
const int A=17,B=25,C=121;
bool grd[N][N],mapp[N][N];
int idd[N][N],val[N];
int L[N],R[N];
int gx[N],gy[N];
void init_ground(){
    L[1]=R[1]=13;
    for(int i=2;i<=4;++i)
        L[i]=L[i-1]-1,R[i]=R[i-1]+1;
    L[5]=1,R[5]=25;
    for(int i=6;i<=9;++i)
        L[i]=L[i-1]+1,R[i]=R[i-1]-1;
    for(int i=10;i<=17;++i)
        L[i]=L[18-i],R[i]=R[18-i];
    int num=0;
    for(int i=1;i<=A;++i){
        for(int j=L[i];j<=R[i];j+=2){
            ++num;
            idd[i][j]=num;
            grd[i][j]=1;
            gx[num]=i;
            gy[num]=j;
        }
    }
    assert(num==C);
}
int tim[N];
vector<int> v[N][N];
int dfs(int x,int t){
    int res=1;
    tim[x]=t;
    for(int i=head[x];i;i=nxt[i]){
        int y=to[i];
        if(val[y]||tim[y]==t||Mid[i]==t) continue;
        res+=dfs(y,t);
    }
    for(int y:v[t][x]){
        if(val[y]||tim[y]==t) continue;
        res+=dfs(y,t);
    }
    return res;
}
int main(){
    int casecnt=read();
    init_ground();
    while(casecnt--){
        n=read();
        for(int i=1;i<=C;++i)
            head[i]=0,tim[i]=-1;
        for(int i=1;i<=C;++i)
            for(int j=1;j<=C;++j)
                v[i][j].clear();
        tot=0;
        for(int i=1;i<=A;++i)
            for(int j=L[i];j<=R[i];j+=2)
                mapp[i][j]=0;
        for(int i=1;i<=n;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            mapp[x][L[x]+y*2-2]=1;
            // cerr<<"x:"<<x<<" y:"<<L[x]+y*2-2<<endl;
        }
        for(int i=1;i<=A;++i){
            for(int j=L[i];j<=R[i];j+=2){
                val[idd[i][j]]=mapp[i][j];
                // cerr<<i<<' '<<j<<' '<<mapp[i][j]<<endl;
                if(!mapp[i][j]) continue;
                int x1=i,y1=j,x2=i,y2=j,cnt=0,last;
                while(1){
                    y1-=2,y2+=2;
                    // cerr<<"!!!"<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                    if(x1<=0||y1<=0||x2<=0||y2<=0||!grd[x1][y1]||!grd[x2][y2]) break;
                    if(cnt==0){
                        add_edge(idd[x1][y1],idd[x2][y2],idd[i][j]);
                        add_edge(idd[x2][y2],idd[x1][y1],idd[i][j]);
                    }
                    else{
                        v[last][idd[x1][y1]].push_back(idd[x2][y2]);
                        v[last][idd[x2][y2]].push_back(idd[x1][y1]);
                    }
                    // cerr<<"Edge1:"<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                    if(mapp[x1][y1])
                        cnt++,last=idd[x1][y1];
                    if(mapp[x2][y2])
                        cnt++,last=idd[x2][y2];
                    if(cnt>=2) break;
                }
            }
        }
        for(int i=1;i<=A;++i){
            for(int j=L[i];j<=R[i];j+=2){
                int x1=i,y1=j,x2=i,y2=j,last,cnt=0;
                if(!mapp[i][j]) continue;
                while(1){
                    ++x1,--y1,--x2,++y2;
                    if(x1<=0||y1<=0||x2<=0||y2<=0||!grd[x1][y1]||!grd[x2][y2]) break;
                    if(cnt==0){
                        add_edge(idd[x1][y1],idd[x2][y2],idd[i][j]);
                        add_edge(idd[x2][y2],idd[x1][y1],idd[i][j]);
                    }
                    else{
                        v[last][idd[x1][y1]].push_back(idd[x2][y2]);
                        v[last][idd[x2][y2]].push_back(idd[x1][y1]);
                    }
                    // cerr<<"Edge2:"<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                    if(mapp[x1][y1])
                        cnt++,last=idd[x1][y1];
                    if(mapp[x2][y2])
                        cnt++,last=idd[x2][y2];
                    if(cnt>=2) break;
                }
            }
        }
        for(int i=1;i<=A;++i){
            for(int j=L[i];j<=R[i];j+=2){
                int x1=i,y1=j,x2=i,y2=j,last,cnt=0;
                if(!mapp[i][j]) continue;
                while(1){
                    --x1,--y1,++x2,++y2;
                    if(x1<=0||y1<=0||x2<=0||y2<=0||!grd[x1][y1]||!grd[x2][y2]) break;
                    if(cnt==0){
                        add_edge(idd[x1][y1],idd[x2][y2],idd[i][j]);
                        add_edge(idd[x2][y2],idd[x1][y1],idd[i][j]);
                    }
                    else{
                        v[last][idd[x1][y1]].push_back(idd[x2][y2]);
                        v[last][idd[x2][y2]].push_back(idd[x1][y1]);
                    }
                    // cerr<<"Edge3:"<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
                    if(mapp[x1][y1])
                        cnt++,last=idd[x1][y1];
                    if(mapp[x2][y2])
                        cnt++,last=idd[x2][y2];
                    if(cnt>=2) break;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=C;++i){
            // int x=gx[i],y=gy[i];
            if(!val[i]) continue;
            // cerr<<gx[i]<<" "<<gy[i]<<' '<<(dfs(i,i)-1)<<endl;
            ans+=(dfs(i,i)-1);
        }
        printf("%d\n",ans);
    }
}