class Solution {
public:
    int maxDepth(string s) {
     
        int opened=0;
        int depth=0;
        
        for(auto i:s){
                
            if(i=='('){
                opened++;
            }
            depth=max(depth,opened);
            
            if(i==')'){
                opened--;
            }
            
            
            
            
        }
        
        
        return depth;
        
        
        
        
    }
};