class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size() , maxlength = 0; 
        int start;
        string ans;
       vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int diff = 0;diff<n;diff++) {
            for(int i=0,j=i+diff; j<n; i++, j++)
            {
                if(i==j) {
                    dp[i][j]=1;
                }
                else if(diff==1){
                    dp[i][j]=(s[i]==s[j])?1:0;   
                } 
                else {
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j] = dp[i+1][j-1]; 
                }
        
                if(dp[i][j]) { 
                    if(j-i+1>maxlength) {
                        maxlength = j-i+1;
                        start=i;
                    }
                }
            } 
        }
        ans=s.substr(start,maxlength);
        return ans;
        
        
        
        
        
    }
};