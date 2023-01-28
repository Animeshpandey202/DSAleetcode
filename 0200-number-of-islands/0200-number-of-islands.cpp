// Method 2: BFS
// Time Complexity : O(n x m)
// Space Complexity: O(n x m)

class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    bool valid_index(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j]='0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;
                int cj=DC[k]+j;
                if(!valid_index(ci, cj, grid))
                    continue;
                if(grid[ci][cj]=='1') {
                    q.push({ci, cj});
                    grid[ci][cj]='0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    no_of_islands++;
                    bfs(i, j, grid);
                }
            }
        }
        return no_of_islands;
    }
};

// /*
//     https://leetcode.com/problems/number-of-islands/
//     TC: O(V^2)
// */
// class Solution {
// public:
//     void DFS(vector<vector<char>>& grid, int i, int j) {
//         // boundary checking
//         if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
//             return;
//         // return if current position is of water or is already visited
//         if(grid[i][j] == '2' || grid[i][j] == '0')
//             return;
        
//         // mark the current as visited
//         grid[i][j] = '2';
        
//         // do DFS in all 4 directions
//         DFS(grid, i+1, j);
//         DFS(grid, i, j-1);
//         DFS(grid, i-1, j);
//         DFS(grid, i, j+1);
//     }
    
//     int numIslands(vector<vector<char>>& grid) {
//         // We can treat the matrix grid as a grid. Each Island is a
//         // connected component. The task is to find no. of disconnectedd components
//         // in the graph.
        
//         int islands = 0;
//         // We make each 1 as 2 in when it is visited
//         for(int i = 0; i < grid.size(); i++) {
//             for(int j = 0; j < grid[0].size(); j++) {
//                 // do DFS in case has not been visited and there is land
//                 if(grid[i][j] == '1') {
//                     DFS(grid, i, j);
//                     ++islands;
//                 } 
//             }
//         }
//         return islands;
//     }
// };