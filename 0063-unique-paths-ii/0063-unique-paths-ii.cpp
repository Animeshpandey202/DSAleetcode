class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&maze) {
        int n=maze.size();
        int m=maze[0].size();
         
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]){
                    dp[i][j]=0;
                    continue;
                } 
                
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                   
 
                int up=0,left=0;
                if(i>0)up = dp[i-1][j];
                if(j>0) left =dp[i][j-1];

                dp[i][j] = up+left;
                
                }
        }
        
        return dp[n-1][m-1];
    
    }
};


//memoize
    // fn tells no of ways to reach from a[0][0] to a[i][j]
    
//         int f(int i,int j,vector<vector<int>>&maze,vector<vector<int>>& dp){
//            if(i<0 || j<0) return 0;
//             if( maze[i][j]==1) return 0; 
//           if(i==0 && j == 0) return 1;
           
          
            
//           if(dp[i][j]!=-1) return dp[i][j];

//           int up = f(i-1,j,maze,dp);
//           int left = f(i,j-1,maze,dp);

//           return dp[i][j] = up+left;

//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>&maze) {
//         int n=maze.size();
//         int m=maze[0].size();
//         vector<vector<int> > dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,maze,dp);
    
//     }
// };


 