class Solution {
//     base case if ds.size()=k store in ans
// if ds.size()>k return
    
// if(i>n)return 
    private:
    void f(int i,int n,int k,vector<int>&ds,vector<vector<int>>&ans){
        
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i>n || ds.size()>k)return;
        
        if(ds.size()==k){
            ans.push_back(ds);
         
        }
        
    
        //take i in ds 
        ds.push_back(i);
        f(i+1,n,k,ds,ans);
    
    
       //not take
        ds.pop_back();
        f(i+1,n,k,ds,ans);
    
    
}  
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        int i=0;
        f(1,n,k,ds,ans);
        return ans;
    }
};


//recursive sol

// ds will initially have 1 in it

// operation take an element and move to next 
// or nottake an element and move to next

