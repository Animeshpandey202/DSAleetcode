class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();   
        deque<int>dq;
        vector<int>ans;
        
        //process first window
        for(int i=0;i<k;++i){
            
            //store in deque in decreasing order
            
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
               
            }
            dq.push_back(i);
            
            
        }
        ans.push_back(nums[dq.front()]);
        
        for(int i=k;i<n;i++){
            
            //remove left overflowing elements from window
            
            while(dq.empty()!=true && dq.front()<=i-k){
                dq.pop_front();
            }
            
            //store current window elem in dq in decreasing order
            
            while(dq.empty()!=true && nums[dq.back()]<=nums[i]){
                dq.pop_back();
                
                
            }
            
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
            
            
        }
        
        return ans;
        
        
    }
};