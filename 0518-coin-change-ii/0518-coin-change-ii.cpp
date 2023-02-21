class Solution {
    
    int f(int ind ,int W,vector<int>&arr,vector<vector<int>>&dp){
        if(ind==0){
            if(W%arr[0]==0)return 1;
            return 0;
        }
        if(dp[ind][W]!=-1)return dp[ind][W];
        int notTake=f(ind-1,W,arr,dp);
        
        int take=0;
        if(arr[ind]<=W){
            take=f(ind,W-arr[ind],arr,dp);
        }
        return dp[ind][W]=take+notTake;
        
        
    }
public:
    int change(int W, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,arr,dp);
    }
};