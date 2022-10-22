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
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>=2){
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            
            if(M[i][j]==1){
                //i knows j..i is not celebrity and j can be
                st.push(j);
            }
            else{
                //i doesnot know j ...i can be celebrity and j cant
                st.push(i);
                
                
            }
            
            
        }
        
        int potn=st.top();
        
        for(int i=0;i<n;i++){
            
            if(i!=potn){
                if(M[potn][i]==1 || M[i][potn]==0){
                    return -1;
                }
                
                
            }
            
            
        }
        return potn;
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