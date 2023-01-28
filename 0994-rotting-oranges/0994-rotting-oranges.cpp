class Solution {
public:
    
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0, time = 0;
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    // push into queue
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        
        // start BFS traversal
        while(!q.empty()){
            
            int size_q = q.size();
            int temp = 0;
            while(size_q != 0){
                
                pair<int, int>p = q.front();
                q.pop();
                
                int x1 = p.first;
                int y1 = p.second;
                
                int dx[4] = { 1, -1, 0, 0};
                int dy[4] = { 0, 0 , 1 , -1};
                
                for(int i=0; i<4; i++){
                    int nx = dx[i] + x1;
                    int ny = dy[i] + y1;
                    
                    if(isValid(nx, ny, n, m, grid)){
                        temp=1;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
                
                size_q--;
                
            }
            if(temp != 0) time++;
        }
        
        
        
        // we checked if any fresh oranges are still there
      
        if(fresh!=0)return -1;
        return time;
        
        
         
        
    }
};