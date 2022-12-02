class Solution {
public:
    bool canJump(vector<int>& nums) {
        
           int n=nums.size();
            int idx=n-1;

        //we try to check from last...ie can we reach from last to start
        
           for(int i=n-2;i>=0;i--){
                //if i +max jump at i >= index ..then we can reach till index idx
               if(i+ nums[i]>=idx){
                   idx=i;    //now we check can reach to new updated index idx or not from lest over arr in left side
               }
           }
               
        //if we could reach till index 0 return true else false
         return idx == 0;  
    }
};