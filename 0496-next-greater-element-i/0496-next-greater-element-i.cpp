class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        //since there are no duplicates, we can store them in a map;
        
        vector<int> res(nums1.size(), -1); //to be returned, initialize it with -1.
        stack<int> st;
        unordered_map<int, int> umap;
        
        for(int i=nums2.size()-1;i>=0; i--)
        {
            int element = nums2[i];
            
            while(!st.empty() && st.top()<=element)
            {
           
                st.pop();
            }
            
            if(st.empty()){
                umap[element]=-1;
            }
            else{
                umap[element]=st.top();
            }
            st.push(element);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            int ele = nums1[i];
            
           int nge = umap[ele];
            res[i] = nge; //push NGE of desired element

                
        }
        
        return res;
        
        
    }
};