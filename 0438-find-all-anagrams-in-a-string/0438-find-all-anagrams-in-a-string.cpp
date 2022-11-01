class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int> ans;
        int k=p.size();
        if(p.size() > s.size())
            return ans;
        
        int left= 0, right = 0;
        while(right < p.size()){
            phash[p[right] - 'a']++;
            shash[s[right] - 'a']++;
            right++;
        }
        if(phash==shash)ans.push_back(left);

        for(;right < s.size();right++){
            //remove char out of window
            char ch=s[left]-'a';
            shash[ch]--;
            left++;
            
            //add current char to window
            shash[s[right]-'a']++;
            
            if(shash==phash){
                ans.push_back(left);
            }
           
        }
        return ans;
    }
};