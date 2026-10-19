const int N = 1e7+10;
int cnt,pr[N/5];
bool vis[N];
void init(int n = 1e7){
    for(int i=2;i<=n;i++){
        if(!vis[i]) pr[++cnt] = i;
        for(int j=1;j<=cnt&&pr[j]*i<=n;j++){
            vis[i*pr[j]] = true;
            if(i % pr[j] == 0) break;
        }
    }
}