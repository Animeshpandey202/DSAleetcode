class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[0][i] != strs[j][i] || i>=strs[j].length())
                {
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};
// https://www.youtube.com/watch?v=1YQmI7F9dJ0