//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    // typedef long long ll;
    private:
    long long KthSmallest(long long v[], long long k, long long n)
{
    priority_queue<long long> maxHeap;
    for (long i = 0; i <n; i++)
    {
        maxHeap.push(v[i]);
        while (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long cost =0;
        long long second = KthSmallest(A, K1,N);
    long long first =KthSmallest(A, K2 ,N);
    
      for(int i=0; i<N; i++){
       if(A[i]>second && first>A[i]){
           cost += A[i];
       }
   }
   return cost;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends