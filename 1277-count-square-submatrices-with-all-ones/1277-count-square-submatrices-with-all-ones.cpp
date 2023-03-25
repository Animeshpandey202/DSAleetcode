class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            dp[i][0]=a[i][0];
           
        }
        for(int j=0;j<m;j++){
            dp[0][j]=a[0][j];
           
        }
       
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                
                if(a[i][j]==1){
                    dp[i][j]= min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    
                }
                 
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=dp[i][j];
            }
        }
        return count;
    }
};