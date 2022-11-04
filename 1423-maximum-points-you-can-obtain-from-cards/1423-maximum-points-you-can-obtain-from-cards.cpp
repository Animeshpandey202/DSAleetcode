class Solution {
public:
    int maxScore(vector<int>& s, int k) {
        int mini=INT_MAX;
        int m=s.size()-k;
        int sum=0;
        int total=0;
        for(int i=0;i<s.size();i++){
            total+=s[i];
        }
        for(int i=0;i<m;i++){
            sum+=s[i];
        }
        
        mini=min(mini,sum);
        
        for(int i=m;i<s.size();i++){
            //remove overflowing el
            sum-=s[i-m];
            
            sum+=s[i];
            
            mini=min(mini,sum);
            
        }
        
        return total-mini;
        

    }
};



// // int mini=INT_MAX;
//         int n=s.size();
//         int prefix[n]; prefix[0]=s[0];
        
//         for(int i=1;i<n;i++){
//             prefix[i]=s[i]+prefix[i-1];
//         }
//         if(n==k)return prefix[n-1];
//         int i=0;
//         for(int j=n-k-1;j<n;j++){
            
//             int sum=prefix[j]-prefix[i]+s[i];
            
            
//             mini=min(mini,sum);
           
            
//             i++;
//         }
        
//         return prefix[n-1]-mini;