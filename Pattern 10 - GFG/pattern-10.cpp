//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution{
public:
    void printTriangle(int N) {
        // code here
        for(int i=0;i<2*N-1;i++){
          
          // stars would be equal to the row no. uptill first half 
          int stars = i+1;
          
          // for the second half of the rotated triangle.
          if(i>=N) stars = 2*N-i-1;
          
          // for printing the stars in each row.
          for(int j=0;j<stars;j++){
              cout<<"* ";
          }
          
           // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
      }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends