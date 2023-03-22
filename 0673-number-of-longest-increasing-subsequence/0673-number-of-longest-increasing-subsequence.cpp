class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>ct(n,1);
        int count=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    ct[i]=ct[j];
                }
                else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                    ct[i]+=ct[j];
                }
                
                
            }
            maxi=max(maxi,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                count+=ct[i];
            }
        }
        return count;
    }
};