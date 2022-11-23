class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //we are looping for whole array hence N and for each element, there will be at max k element in heap, so storing each element takes logK time. so NlogK
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<nums.size();i++){
            
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
        
        
    }
};