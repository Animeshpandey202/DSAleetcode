class Solution {
    public:
    bool isSafe1(int row, int col, vector < string > board, int n) {
      int i = row;
      int j = col;

      while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q')
          return false;
        i--;
        j--;
      }
      
      i = row;  
      j = col;
     
      while (j >= 0) {
        if (board[i][j] == 'Q')
          return false;
        j--;
      }

      i = row;
      j = col;
      while (i < n && j >= 0) {
        if (board[i][j] == 'Q')
          return false;
        i++;
        j--;
      }
      return true;
    }
    
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
     vector < vector < string >> ans;
      vector < string > board;
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board.push_back(s);
      }
    for(auto it:board){
        cout<<it<<endl;
    }
        
      solve(0, board, ans, n);
      return ans;
        
    }
};



