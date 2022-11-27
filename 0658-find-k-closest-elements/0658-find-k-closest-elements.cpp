
class Solution {
    public:
    
    static bool cmp(pair<int,int> &a, pair<int,int> &b) {
        if(a.second!=b.second){
            return a.second<b.second;
        }
        else{
            return a.first < b.first;
        }
        
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],abs(arr[i]-x)});

        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

};