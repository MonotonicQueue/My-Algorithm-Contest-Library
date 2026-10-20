#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 4010;
int n;
vector<int> v[N];
bitset<N> G[256*2][N];
void init(vector<vector<bool>> F,int _n){
    n = _n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            G[0][i][j] = F[i][j];
    for(int s=1;s<512;s++){
        int d = s&(-s),pre = s^d;
        for(int i=0;i<n;i++) {
            G[s][i] = G[pre][i]^(G[pre][i]<<d);
            if(i >= d) G[s][i] ^= G[pre][i-d]^(G[pre][i-d]<<d);
        }
    }       
}
vector<bool> query(vector<array<int,3>> ask){
    vector<bool> ans;
    for(auto [k,x,y] : ask){
        if(k == 0){
            ans.push_back(G[0][x][y]);
            continue;
        }
        k = (k-1)%4096;
        int L = k%512,rH = (k>>9);
        bool r = 0;
        auto &A = G[(~L)&511];
        int H = (~rH) & 7;
        for(int sx=H;;sx=(sx-1)&H){
            for(int sy=H;;sy=(sy-1)&H){
                int i = x-(sx << 9);
                int j = y-(sy << 9);
                if (i >= 0 && j >= 0)
                    r ^= A[i][j];
                if(!sy) break;
            }
            if(!sx) break;
        }
        ans.push_back(r);
    }
    return ans;
}
//g++ sample_grader.cpp code.cpp -o code -std=gnu++14 -O2 -static