class Solution {
public:
    int totalFruit(vector<int>& s) 
    {
        int i = 0, j = 0, k = 2, sz = s.size(), maxi = 0 ;
        unordered_map<int,int>mp;
        
        for(int j=0;j<sz;j++){
            
            //acquire
            mp[s[j]]++;
            
            
            //remove if invalid 
            
            if(mp.size()>k){
                
                while(mp.size()>k){
                    
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                
            }
            maxi=max(maxi,j-i+1);
            
            
        }
        
        return maxi;
         
      
    }
};
//   unordered_map<int, int> umap ;
        
//         while(j<sz)
//         {
//             umap[fruits[j]]++ ;
            
//             if(umap.size() <= k)
//             {
//                 maxm = max(maxm, j-i+1) ; j++ ;
//             }
//             else if(umap.size() > k)
//             {
//                 while(umap.size() > k)
//                 {
//                     umap[fruits[i]]-- ;
//                     if(umap[fruits[i]] == 0){ umap.erase(fruits[i]) ; }
//                     i++ ;
//                 }
//                 if(umap.size()==k)maxm = max(maxm, j-i+1) ;
//                 j++ ;
//             }
//         }
//         return maxm ;