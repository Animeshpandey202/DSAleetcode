class Solution {
    
 void f(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&updig,vector<int>&downdig,int n){
     
     if(col==n){
         ans.push_back(board);
         return;
     }
     
     //insert Q in col
     
     for(int row=0;row<n;row++){
         //safe to insert
         if(leftrow[row]==0 && updig[n-1+col-row]==0 && downdig[row+col]==0){
             //inset Q
             board[row][col]='Q';
             
             //update diagonal arrays
             leftrow[row]=1;
             updig[n-1+col-row]=1;
             downdig[row+col]=1;
             
             //recursive call
             f(col+1,board,ans,leftrow,updig,downdig,n);
             
             //backtrack
             board[row][col]='.';
             
             //update diagonal arrays to previos state
             leftrow[row]=0;
             updig[n-1+col-row]=0;
             downdig[row+col]=0;
             
         }
 
         
     }

     
 }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        string s(n,'.');
        vector<string>board;
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        //initializing leftrow ,up diagonal and low diagnal
        
        vector<int>leftrow(n,0),updig(2*n-1,0),downdig(2*n-1,0);
        
        
        vector<vector<string>>ans;
        f(0,board,ans,leftrow,updig,downdig,n);
        return ans;       
        
        
    }
};