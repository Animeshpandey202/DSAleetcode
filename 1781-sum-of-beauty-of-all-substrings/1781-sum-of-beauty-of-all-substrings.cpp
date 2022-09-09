class Solution {
public:
    int beautySum(string s) {
     
        
     
       
        int sum=0;
        
        for(int i=0;i<s.length();i++){
            
            unordered_map<char,int>mp;
            
            for(int j=i;j<s.length();j++){
                
                mp[s[j]]++;
                
                int minf=INT_MAX;;
                int maxf=INT_MIN;    
                
                for(auto it:mp){
                    
                    maxf=max(maxf,it.second);
                    minf=min(minf,it.second);
                    
                }
                sum+=maxf-minf;
                
                
                
                
            }
            
        }
        return sum;
        
        
        
        
        
        
        
        
    }
};