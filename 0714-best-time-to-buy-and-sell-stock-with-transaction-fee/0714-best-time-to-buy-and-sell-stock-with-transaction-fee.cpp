class Solution {
    int fn(int ind,int buy,vector<int>&arr,int n,vector<vector<int>>&dp,int fee){
        if(ind==n)return 0;
        
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0; 
        
        if(buy==0){
            profit=max(0+fn(ind+1,0,arr,n,dp,fee), -arr[ind] +fn(ind+1,1,arr,n,dp,fee)); 
        }
        if(buy==1){
            profit=max(0 +fn(ind+1,1,arr,n,dp,fee),+arr[ind] -fee +fn(ind+1,0,arr,n,dp,fee));
        }
        
        return dp[ind][buy]=profit;
        
        
    }
    
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(0,0,prices,n,dp,fee);
    }
};