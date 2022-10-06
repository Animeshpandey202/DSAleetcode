class Solution {
    void f(int ind,vector<int>&ds,vector<vector<int>>&ans,vector<int>& arr,int n){
        //for nth call try to make subset of size n
        ans.push_back(ds);
        
        if(ind==n)return;
        
        for(int i=ind;i<n;i++){
            
            if(i>ind && arr[i]==arr[i-1])continue;
            
            ds.push_back(arr[i]);
            f(i+1,ds,ans,arr,n);
            ds.pop_back();               
        }   
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n=arr.size();
        f(0,ds,ans,arr,n);
        return ans;
        
        
    }
};