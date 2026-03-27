#include <bits/stdc++.h>
using namespace std;

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
    dp[0][0][grid[0][0]%k]=1;
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            for(int v=0;v<k;v++){
                if(i>0){
                    dp[i][j][v]=(dp[i][j][v] + dp[i-1][j][(v-grid[i][j]%k+k)%k] )%mod;
                }
                if(j>0){
                    dp[i][j][v]=(dp[i][j][v] + dp[i][j-1][(v-grid[i][j]%k+k)%k] ) %mod;
                }
            }
        }
    }
    return dp[n-1][m-1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> grid={{5,2,4},{3,0,5},{0,7,2}};
    cout<<numberOfPaths(grid,3)<<endl;
    return 0;
}