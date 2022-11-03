class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_map < int,int > mp;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
     mp[str[r]]++; 
      
      
    if (mp[str[r]]>1) //if duplicate element is found
    {
      while (l < r && mp[str[r]]>1) {
         mp[str[l]]--; 
        
          if(mp[str[l]]==0){
              mp.erase(str[l]);
          }
        l++;
      }
    }
    
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
        
        
        
    }
};