class Solution {
public:
    
    bool  bfs(vector<vector<int>>& graph, vector<int>& color, int startNode){
        
        queue<int> q;        
        
        q.push(startNode);
        color[startNode] = 0;
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                
                else if(color[it]==color[node]){
                    return false;
                }
                
            }
             
            
            
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph){
        
        int n = graph.size();
   
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            
            if(color[i] == -1){
                if(bfs(graph, color, i)==false)return false;
                
            }
            
        }
        
        return true;
        
    }
    
    
};