class Solution {
private:
    int largestArea(vector<int>& heights) {
        //tc=O(n)  sapce=O(3n)
        
        int n=heights.size();
        stack<int>st;
        int ls[n];
        int rs[n];
        
        
        for(int i=0;i<n;i++){
            
            while(st.empty()!=true && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ls[i]=0;
            }else{
                ls[i]=st.top()+1;
            }
            st.push(i);
            
            
        }
        
        while(st.empty()!=true){
            st.pop();
        }
        
        int maxA=0;
        for(int i=n-1;i>=0;i--){
            
            while(st.empty()!=true && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rs[i]=n-1;
            }
            else{
                rs[i]=st.top()-1;
            }
            st.push(i);
            
            maxA=max(maxA,heights[i]*(rs[i]-ls[i]+1));
        }
        
        return maxA;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size(), result=0;
        vector<int> curRow(m);
        int maxi=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1')
                    curRow[j]+=1;
                else
                    curRow[j]=0;
            }
            result = largestArea(curRow);
            maxi=max(maxi,result);
            
        }
        return maxi;
    }
};