class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        
        int max_reach=0;
        int curr_reach=0;
        int jump=0;
        
        for(int i=0;i<n-1;i++){
            
            //checking whether cuurent jump option > max reach
            if(i+arr[i]>max_reach){ 
                max_reach=i+arr[i]; 
            }
            
            if(i==curr_reach){ //all current reach options are tried
                //now choose next optimal jump
                jump++;
                curr_reach=max_reach;
            }
        }
        return jump;
        
    }
};
