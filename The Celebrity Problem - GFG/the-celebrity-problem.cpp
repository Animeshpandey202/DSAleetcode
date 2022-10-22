//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int celebrity=-1;
        for(int i=0;i<n;i++){
            bool knows_anyone=false;
            bool everyone_knows=true;
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    knows_anyone=true;
                    break;
                }
            
                if(M[j][i]==0 && i!=j){
                    everyone_knows=false;
                    break;
                }
            }
         if(!knows_anyone && everyone_knows){
            return i;
            
        }
        
        }
    return celebrity;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends