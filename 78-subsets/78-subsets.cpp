class Solution {
    
private:
    void f(int i,vector<int>ds,vector<int>&nums,vector<vector<int>>&ans){
        
        if(i>=nums.size()){
            ans.push_back(ds);
            return;
        }
        
        //take option
        
        ds.push_back(nums[i]);
        f(i+1,ds,nums,ans);
        
        //undo take option
        ds.pop_back();
        
        //not take option
        f(i+1,ds,nums,ans);
            
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans; 
    vector<int>ds;
    f(0,ds,nums,ans);
        
    return ans;    
        
        
    }
};