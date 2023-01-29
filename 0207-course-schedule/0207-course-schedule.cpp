class Solution {
    private:
     bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){        
         vis[node]=1;
         pathvis[node]=1;
         
         for(auto it:adj[node]){
             
             if(!vis[it]){
                 if(dfs(it,adj,vis,pathvis)==true)return true;
             }
             else if(pathvis[it]){
                 return true;
             }
             
         }
         pathvis[node]=0;
         return false;
        
         
     }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            
        }
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true)return false;
            }
        }
        return true;
        
        
    }
};