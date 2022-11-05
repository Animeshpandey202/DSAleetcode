class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int w=0;
        int b=0;
        
        //first window solve
        
        for(int i=0;i<k;i++){
            
            if(blocks[i]=='W')w++;
        }
        int mini=w;
        
        for(int i=k;i<blocks.size();i++){
            
            if(blocks[i-k]=='W')w--;
            
            if(blocks[i]=='W')w++;
            
            mini=min(mini,w);
            
            
        }
        return mini;
        
        
    }
};