class Solution {
//     f(int ind1,int ind2 ,string s1,string s2,vector<vector<int>>dp){
        
// //         if(ind1<0 || ind2<0)return 0;
        
// //         if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
// //         if(s1[ind1]==s2[ind2]){
// //             match= 1+f(ind1-1,ind2-1);
// //         }
// //         else{
// //             notmatch=max(f(ind1-1,ind2) ,f(ind1,ind2-1);
// //         }
// //         return dp[ind1][ind2]=max(match,notmatch);
        
        
//     }
    int lcs(string s1,string s2){
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //shifting the index i=0 means a[-1]  i=1 means a[0]
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=0,notmatch=0;
                if(s1[i-1]==s2[j-1]){
                    match=1+dp[i-1][j-1];
                }
                else{
                    notmatch=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=max(match,notmatch);
                
            }
        }
        return dp[n][m];
    }
    
    
    
public:
    int minInsertions(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        int l=lcs(s,t);
        return n-l;
    }
};