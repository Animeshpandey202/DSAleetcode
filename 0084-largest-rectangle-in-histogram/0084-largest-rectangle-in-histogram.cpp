class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
         int n=nums.size();
        int ls[n];
        int rs[n];
       
        for(int i=0;i<n;i++){
            
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ls[i]=0;
            }
            else{
                ls[i]=st.top()+1;
            }
            st.push(i);
            
        }
        int maxi=0;
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                rs[i]=n-1;
            }
            else{
                rs[i]=st.top()-1;
            }
            st.push(i);
            
            int curA=nums[i]*(rs[i]-ls[i]+1);
            maxi=max(maxi,curA);
            
        }
        return maxi;
        
        
    }
};