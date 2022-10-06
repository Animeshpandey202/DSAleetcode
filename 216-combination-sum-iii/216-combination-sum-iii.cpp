class Solution {
public:
    void f(vector<int>& ds, int ind, int k, int n,vector<vector<int>>& ans) {
        
        if(n == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if(n < 0 || ds.size() > k) return;
        
        for(int i=ind; i<=9; ++i) {
            ds.push_back(i);
            f(ds, i+1, k, n-i,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> ds;
        f(ds, 1, k, n,ans);
        return ans;
    }
};