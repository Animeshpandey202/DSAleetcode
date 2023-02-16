class Solution {
    bool f(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        
        if(target==0)return true;
        
        if(ind==0)return nums[0]==target;
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        bool notTake=f(ind-1,target,nums,dp);
        bool take=false;
        
        if(nums[ind]<=target){
            take=f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take||notTake;
        
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            sum += nums[i];
        }
        if(sum & 1) //if sum is odd
            return false;
        sum = sum/2;
        //dp[i][j] -> if sum 'i' is possible with elements from 0 to j-1
        //dp[sum+1][n]
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};