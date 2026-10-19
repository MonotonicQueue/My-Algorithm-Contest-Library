#include<bits/stdc++.h>
using namespace std;
const int fx[10] = {0,0,0,1,1,1,-1,-1,-1};
const int fy[10] = {0,1,-1,0,1,-1,0,-1,1};
int mp[10][10];
int f[10][10];
int n,m,ans;
void dfs(int x,int y,int sum){
 if(y == m+1) x++,y=1;
 if(x == n+1){ans = max(ans,sum); return;}
 if(f[x][y] == 0){
  for(int i = 0;i<=8;i++)
   f[x+fx[i]][y+fy[i]]++;
  dfs(x,y+1,sum+mp[x][y]);
  for(int i = 0;i<=8;i++)
   f[x+fx[i]][y+fy[i]]--;
 }
 dfs(x,y+1,sum);
}
int main(){
 int T;
 cin >> T;
 while(T--){
  cin >> n >> m;
  ans = 0;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    cin >> mp[i][j];
  dfs(1,1,0);
  cout << ans << "\n";
 }
 return 0;
}