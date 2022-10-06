class Solution {
    bool ispalindrome(int start,int end,string &s){
        while(start<end){
            
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
    
    void f(int ind,vector<string>&ds,vector<vector<string>>&ans,string s,int n){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        
        //pation at a call possible from index i=ind to n-1
        
        for(int i=ind;i<n;i++){
            
            //start index =ind ending =i
            if(ispalindrome(ind,i,s)){
                
                string sub=s.substr(ind,i-ind+1);
                ds.push_back(sub);
                f(i+1,ds,ans,s,n);
                ds.pop_back();
                
            }    
        }
           
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string> ds;
        int n=s.length();
        f(0,ds,ans,s,n);
        return ans;
        
         
        
    }
};