class Solution {
public:
    int jump(vector<int>& arr) {
        
        int n = arr.size();
        
        int jumps = 0;
        
        // max_jump will keep track of maximum index we can reach from all the index less than max_reach
        
        int max_jump = 0;
        
        // max_reach will keep track of maximum index we can reach till now
        
        int max_reach = 0;
        
        int i = 0;
        
        while(i < n && max_reach < n - 1)
        {
            int curr_jump = i + arr[i];
            
            max_jump = max(max_jump, curr_jump);
            
            // update max_reach && increment jumps
            
            if(i == max_reach && max_jump > max_reach)
            {
                jumps++;
                
                max_reach = max_jump;
            }
            
            i++;
        }
        
        // if we can't reach the last index
        
        if(max_reach < n - 1)
        {
            return -1;
        }
        
        return jumps;
    }
};
