class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // time=O(n)
        // space=O(1) or O(256) to be precise
        
        //sliding window approach
        
        map<char,int>m;
        
        int left=0;
        int right=0;
        int n=s.size();
        int len=0;
        
        while(right<n){
            
            if(m.find(s[right])!=m.end()){   //if it already exist in our substring
                
                left=max(m[s[right]]+1,left);   //left will point to next index of where element at right prexist
            }
            
            m[s[right]]=right;   //store in map where element at right last found
            
            len=max(len,right-left+1);   //find length of substring b/w left and right
            right++;
        }
        
        return len;
        
        
        
        
    }
};