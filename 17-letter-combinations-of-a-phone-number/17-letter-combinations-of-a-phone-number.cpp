class Solution {
    private:
    void f(int ind,string &ds,vector<string>&map,vector<string>&ans,string &digits,int n){
            
            if(ind==n){
                ans.push_back(ds);
                return;
            }
        
            int number=digits[ind]-'0'; //digit="23"   ind=0  then number=2
        
            string val=map[number];  //val="abc"
        
            for(int i=0;i<val.length();i++){
                
                ds.push_back(val[i]);
                f(ind+1,ds,map,ans,digits,n);
                
                ds.pop_back();
                                
            }
        }
    
public:
    vector<string> letterCombinations(string digits) {
          vector<string>ans;
        if(digits.length()==0)return ans;
        
        vector<string>map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      
        string ds;
        int n=digits.length();
        f(0,ds,map,ans,digits,n);
        
        return ans;
        
        
    }
};