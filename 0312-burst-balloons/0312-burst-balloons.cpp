class Solution {
   
// private:
    
//     int f(int i,int j,vector<int>a,vector<vector<int>>&dp){

        
//         if(i>j)return 0; //no element
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int maxi=INT_MIN;
        
//         for(int index=i;index<=j;index++){
            
//             int val= a[index]*a[i-1]*a[j+1] +f(i,index-1,a,dp)+ f(index+1,j,a,dp);
            
//             maxi=max(maxi,val);
            
//         }
//         return dp[i][j]=maxi;   
        
//     }
    
    
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     
//         return f(1,n,nums,dp);
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        //base case already covered
        
        //in memo i 1->n ..tabu n->1   ,,, j n->1 to 1 to n  also i+1 as j alwys ahead of i
       
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                
                int maxi=INT_MIN;
                
                for(int index=i;index<=j;index++){

                    int val= nums[index]*nums[i-1]*nums[j+1] +dp[i][index-1]+ dp[index+1][j];

                    maxi=max(maxi,val);
                    
                    

                }
                 dp[i][j]=maxi;
                   
            }
        }
        return dp[1][n];
            
        
    }
};