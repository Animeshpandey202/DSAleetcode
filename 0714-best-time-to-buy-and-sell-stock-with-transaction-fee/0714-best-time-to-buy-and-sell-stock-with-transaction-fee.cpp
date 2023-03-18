class Solution {
//     int fn(int ind,int buy,vector<int>&arr,int n,vector<vector<int>>&dp,int fee){
//         if(ind==n)return 0;
        
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
//         int profit=0; 
        
//         if(buy==0){
//             profit=max(0+fn(ind+1,0,arr,n,dp,fee), -arr[ind] +fn(ind+1,1,arr,n,dp,fee)); 
//         }
//         if(buy==1){
//             profit=max(0 +fn(ind+1,1,arr,n,dp,fee),+arr[ind] -fee +fn(ind+1,0,arr,n,dp,fee));
//         }
        
//         return dp[ind][buy]=profit;
        
        
//     }
    
    
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0; 
        
                if(buy==0){
                    profit=max(0+dp[ind+1][0], -arr[ind] +dp[ind+1][1]);
                }
                if(buy==1){
                    profit=max(0 +dp[ind+1][1],+arr[ind]-fee +dp[ind+1][0]) ;
                }

                 dp[ind][buy]=profit;
            }
        }
        
        return dp[0][0];
    }
};