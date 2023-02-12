class Solution {
    // fn tells no of ways to reach from a[0][0] to a[i][j]
    
        int f(int i,int j,vector<vector<int>>&maze,vector<vector<int>>& dp){
           if(i<0 || j<0) return 0;
            if( maze[i][j]==1) return 0; 
          if(i==0 && j == 0) return 1;
           
          
            
          if(dp[i][j]!=-1) return dp[i][j];

          int up = f(i-1,j,maze,dp);
          int left = f(i,j-1,maze,dp);

          return dp[i][j] = up+left;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&maze) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        return f(n-1,m-1,maze,dp);
    
    }
};

 