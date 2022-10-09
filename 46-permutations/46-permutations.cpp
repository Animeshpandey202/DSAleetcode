class Solution {
  void f(map<int,int>&mp,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,int n)  {

    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    
    
    //try all possible combos
    
    for(auto it:nums){
        
        if(mp[it]==0){
            ds.push_back(it);
            mp[it]=1;
            f(mp,ds,ans,nums,n);
            
            ds.pop_back();
            mp[it]=0;
        }
    }
    
  }   
    
   
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto it:nums){
            mp[it]=0;
        }
        
        vector<int>ds;
        vector<vector<int>>ans;
        f(mp,ds,ans,nums,n);
        return ans;
    }
};