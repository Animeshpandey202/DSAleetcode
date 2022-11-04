class Solution {
    //no of subarray with atmost k different integer
    int solve(vector<int>&a,int k){
        int i=0,j=0,count=0;
        unordered_map<int,int>mp;
        
        for(int j=0;j<a.size();j++){
            //acquire
            mp[a[j]]++;
            
            
            //release if invalid
            while(mp.size()>k){
                
                mp[a[i]]--;
                if(mp[a[i]]==0)mp.erase(a[i]);
                i++;
                
            }
            
            count+=j-i+1;
            
        }
        return count;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};