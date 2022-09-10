class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //time=nklogk
        
        vector<vector<string>>ans;
        
        unordered_map<string,vector<string>>mp;
        string temp;
        for(int i=0;i<strs.size();i++){
            
            temp=strs[i];
            
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        
        for(auto i=mp.begin();i!=mp.end();i++){
            ans.push_back(i->second);
        }
        return ans;
    }
};
