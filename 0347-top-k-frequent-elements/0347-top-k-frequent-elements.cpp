class cmp{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        
        for(auto it:mp){
            pq.push({it.first,it.second});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};