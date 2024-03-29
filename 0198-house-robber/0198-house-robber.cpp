class Solution {
    
public:
    int rob(vector<int>& nums) {
       
        int n=nums.size();
        
        vector<int>dp(n,-1);
        dp[0]=nums[0];
      
         
        
        for(int i=1;i<n;i++){  // 0 1 2
            
            int pick=nums[i];
            if(i>1)pick+=dp[i-2] ;
        
            int notpick=0+dp[i-1] ;

           dp[i]=max(pick,notpick);
        }
         
        
         return dp[n-1];
    }
};