class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
        
        //dp[i][j] will tell cost from a[0,0] to a[i,j]
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) {
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int up=0;
                int left=0;
                if(i>0) up=grid[i][j] +dp[i-1][j];  //means we reached curr cell by moving down from previos cell
                else up=1e9;        
                if(j>0) left=grid[i][j]+dp[i][j-1];  //means we reached curr cell by moving right from previos cell
                else left=1e9;
                
                dp[i][j]=min(up,left);
                
                
            }
        }
        return dp[n-1][m-1];
        
        
        
        
        
    }
};

// int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
// {
//       if(i==0 && j == 0)
//         return matrix[0][0];
//       if(i<0 || j<0)
//         return 1e9;
//       if(dp[i][j]!=-1) return dp[i][j];

//       int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
//       int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);

//       return dp[i][j] = min(up,left);

//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int> > dp(n,vector<int>(m,-1));
//         return minSumPathUtil(n-1,m-1,grid,dp);   
//     }