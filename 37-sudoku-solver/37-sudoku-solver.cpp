class Solution {
    bool isSafe(char c,int row,int col,vector<vector<char>>&m){
        
        
        for(int i=0;i<9;i++){
            
            if(m[row][i]==c)return false;
            
            if(m[i][col]==c)return false;
            
            if(m[3*(row/3) +i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;    
    }
    
    bool f(vector<vector<char>>&m){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){        
                //empty cell found
                if(m[i][j]=='.'){
                    //trying all possible nos
                    for(char c='1';c<='9';c++){
                        //check its safe or not
                        if(isSafe(c,i,j,m)){
                            m[i][j]=c;
                            //recursively call the same fn with updated board
                            if(f(m)==true){ //means no empty cell ...thus dont try any other char 
                                return true;
                            }
                            //if not got answer wid chosen c ..thn try rest no ...after restoring to empty cell 
                            m[i][j]='.';
                        }
                    }
                    return false; 
                }
                
                
            }
        }
        return true;
        
    }
    
public:
    void solveSudoku(vector<vector<char>>& m) {
        //we have to make change in existing board
        f(m);
        
    }
};