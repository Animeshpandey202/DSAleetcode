class Solution {
    bool f(int i,int j,vector<vector<char>>& arr,string &word,int count){
        
        if(count==word.length())return true;
        
        
        
        if(i==-1 || j==arr[0].size()|| i==arr.size()|| j==-1 || arr[i][j]!=word[count] )return false;
        
        // count++;
        char temp=arr[i][j];
        arr[i][j]='*';
        bool res= f(i-1,j,arr,word,count+1)||
                    f(i+1,j,arr,word,count+1)||
                    f(i,j+1,arr,word,count+1)||
                    f(i,j-1,arr,word,count+1);
            
        //backtrack
        arr[i][j]=temp;
        return res;
        
        
    }
    
    
    
    
public:
    bool exist(vector<vector<char>>& arr, string word) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                
                if(arr[i][j]==word[0] && f(i,j,arr,word,0)){
                    return true;
                }
                
            }
        }
        
        return false;
        
    }
};