class Solution {
    void f(int ind,vector<int>&nums,vector<vector<int>>&ans,int n){
        
        if(ind==n){
            ans.push_back(nums);
        }
        
        // 4 5 6
        for(int i=ind;i<n;i++){
            // 5 4 6
            swap(nums[ind],nums[i]);
            
            f(ind+1,nums,ans,n);
            
            swap(nums[ind],nums[i]);
            
            
        }
        
        
        
        
        
        
        
    }
    

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        f(0,nums,ans,n);
        return ans;
        
        
        
    }
};