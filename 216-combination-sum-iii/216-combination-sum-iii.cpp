class Solution {
    
    void f(int i,vector<int>&ds,vector<vector<int>>&ans,vector<int>&arr,int k,int n){
        
       
        if(n<0 || ds.size()>k)return;
        if(ds.size()==k && n==0){
            ans.push_back(ds);
            return;
        }
         if(i==arr.size())return;
        
        //take
        ds.push_back(arr[i]);
        f(i+1,ds,ans,arr,k,n-arr[i]);
        
        ds.pop_back();
        
        f(i+1,ds,ans,arr,k,n);
        
        
        
    }
    
    
    
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,ds,ans,arr,k,n);
        return ans;
        
    }
};