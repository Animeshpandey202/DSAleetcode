//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
                                                 
    vector<long long>ans;
    deque<long long>dq;
    //first window process
    int cur=0;
    for(int i=0;i<k;i++){
        
        if(a[i]<0){
            dq.push_back(i);
        }
        
        
    }
    if(dq.size()==0){
        ans.push_back(0);
    }
    else{
        ans.push_back(a[dq.front()]);
    }
  
    for(int i=k;i<n;i++){
        
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        if(a[i]<0){
            dq.push_back(i);
        }
         if(dq.size()==0){
        ans.push_back(0);
        }
        else{
            ans.push_back(a[dq.front()]);
        }
    }
    return ans;
 }