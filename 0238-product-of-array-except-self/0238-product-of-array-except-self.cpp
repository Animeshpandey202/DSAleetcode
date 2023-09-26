class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time Complexcity : O(n)
        // Space Complexcity : O(1)
        int n=nums.size();
        vector<int> ans(n);
        
        //leftpass
        int lp=1;
        for(int i=0;i<n;i++){
            ans[i]=lp;
            lp=lp*nums[i];     //left running product
        }
        int rp=1;
        for(int i=n-1;i>=0;i--){
            
            ans[i]=ans[i]*rp;      // multiplying leftproduct with right product
            rp=rp*nums[i];         //right running product
        }
        return ans;
    }
};


 // brute force approach: time=o(n^2) sapce=o(1) as output array space not counted       
//         int n = nums.size();
//         vector<int> ans(n, 1);
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(i == j) continue;
//                 ans[i] = ans[i] * nums[j]; 
//             }
//         }

//         return ans;
//     }
// };
// https://www.youtube.com/watch?v=10NJzNaSsrg