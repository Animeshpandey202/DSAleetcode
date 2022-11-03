class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int j=0,i=0,zeros=0;
        int maxi=0;
        int n=s.size();
        for(int j=0;j<n;j++){
            
            
            //accuire till zero<=k || s[j]=1
            if(s[j]==1 || zeros<=k){
                
                if(s[j]==0)zeros++;
            } 
            
            while(zeros>k){
                if(s[i]==0)zeros--;
                i++;
                
            }
            maxi=max(maxi,j-i+1);
            
            
        }

        return maxi;
          
    }
};



//     int start = 0, end = 0, zeros = 0, res = 0;
        
//         for (end = 0; end < nums.size(); end++) {
            
//             // If we reached a zero, increase the zero counter.
//             if (!nums[end])
//                 zeros++;
            
//             // If the number of zeros is more than k, we finished with this subarray.
//             // Now we can save the length and continue looking if we find a better one.
//             while (zeros > k) {
//                 if (!nums[start]) zeros--;
//                 start++;
//             } 
            
//             res = max(res, end - start + 1);
//         }
        
//         return res;