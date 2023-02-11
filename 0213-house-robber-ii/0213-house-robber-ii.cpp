class Solution {
    private:
     int f(vector<int> a) {
       
        int n=a.size();
        int prev=a[0];
         int prev2=0;
         
           
        for(int i=1;i<n;i++){  // 0 1 2
            
            int pick=a[i];
            if(i>1)pick+=prev2;
        
            int notpick=0+prev;

           int curi=max(pick,notpick);
              prev2=prev;
            prev=curi;
        }
         
         return prev;
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
 