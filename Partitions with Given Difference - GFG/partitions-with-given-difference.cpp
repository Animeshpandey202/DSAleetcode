//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod =(int)1e9+7;

    int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
    <int>> &dp){
    
         if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
        
        int taken = 0;
        if(arr[ind]<=target)
            taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= (notTaken + taken)%mod;
    }

  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        // if(totSum-d<0) return 0;
        if((totSum+d)%2==1) return 0;
        
        int s2 = (totSum+d)/2;
        
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return countPartitionsUtil(n-1,s2,arr,dp);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends