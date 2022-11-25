class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>v;
        
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});    
        }
        
        sort(v.begin(),v.end());
        vector<int>ans(arr.size(),0);
        //{ (10,1) (20,2) (30,3) (40,0) }
        int rank=1;
        for(int i=0;i<v.size();i++){
            int idx=v[i].second;
            
            if(i>0 && v[i-1].first== v[i].first){          //current and prev no same 
                    ans[idx]=rank-1;
                    
            }else{
                ans[idx]=rank;
                rank++;
            }
            
        }
        return ans;
        
        
    }
};