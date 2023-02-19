class Solution {
    int f(int i,int w,vector<int>&arr,vector<vector<int>>&dp){
        if(i==0){
            if(w%arr[i]==0){
                return w/arr[i];
            }
            else{
                return 1e9;
            }
        }
        if(w==0)return 0;
        if(dp[i][w]!=-1)return dp[i][w];
        
        int notTake=0+ f(i-1,w,arr,dp);
        
        int take=1e9;
        if(arr[i]<=w){
         take=1+f(i,w-arr[i],arr,dp);
        }
        
        return dp[i][w]=min(take,notTake);
        
    }
public:
    int coinChange(vector<int>& arr, int T) {
        int n= arr.size();
    
        vector<vector<int>> dp(n,vector<int>(T+1,-1));
        int ans=f(n-1,T,arr,dp);

        if(ans>=1e9)return -1;

        return ans;
 
    }
};

//  int coinChange(vector<int>& arr, int T) {
//     int n= arr.size();
    
//     vector<vector<int>> dp(n,vector<int>(T+1,0));
    
//     for(int i=0; i<=T; i++){
//         if(i%arr[0] == 0)  
//             dp[0][i] = i/arr[0];
//         else dp[0][i] = 1e9;
//     }
//     for(int i=0;i<n;i++){
//         dp[i][0]=0;
//     }
    
//     for(int ind = 1; ind<n; ind++){
//         for(int target = 1; target<=T; target++){
            
//             int notTake = 0 + dp[ind-1][target];
//             int take = 1e9;
//             if(arr[ind]<=target)
//                 take = 1 + dp[ind][target - arr[ind]];
                
//              dp[ind][target] = min(notTake, take);
//         }
//     }
    
//     int ans = dp[n-1][T];
//     if(ans >=1e9) return -1;
//     return ans;
//     }