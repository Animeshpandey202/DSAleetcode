class Solution {
    private:
     int f(vector<int> a) {
       
        int n=a.size();
        
        vector<int>dp(n,-1);
        dp[0]=a[0];    
        
        for(int i=1;i<n;i++){  // 0 1 2
            
            int pick=a[i];
            if(i>1)pick+=dp[i-2] ;
        
            int notpick=0+dp[i-1] ;

           dp[i]=max(pick,notpick);
        }
         
         return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        //if we pick 0 house cant pick last and vice-versa
        vector<int>leaveone,leavelast;
        for(int i=0;i<nums.size();i++){
            if(i!=0)leaveone.push_back(nums[i]);
            if(i!=nums.size()-1)leavelast.push_back(nums[i]);
        }    
        for(auto it:leavelast)cout<<it;
        return max(f(leaveone),f(leavelast));
    }
};
// class Solution {
// public:
//     int houseRobber(vector<int>& nums) {
//         // dynamic programming - decide each problem by its sub-problems:
        
        
//         int dp[nums.size()+1];
//         dp[0] = nums[0];
//         dp[1] = max(nums[0], nums[1]);
//         for (int i=2; i<nums.size(); i++)
//             dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
//         return dp[nums.size()-1];
//     }
    
//     int rob(vector<int>& nums) {
        
//         // either use first house and can't use last or last and not first:
//         vector<int> v1(nums.begin(), nums.end()-1);
//         vector<int> v2(nums.begin()+1, nums.end());
//         return max(houseRobber(v1), houseRobber(v2));
//     }
// };