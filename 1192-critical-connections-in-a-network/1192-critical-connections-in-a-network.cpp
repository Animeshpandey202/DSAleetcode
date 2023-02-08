class Solution {
private:
    void dfs(int node,int parent,vector<int>&disc,vector<int>&low,int &timer,vector<bool>&vis,vector<int>adj[],vector<vector<int>>&result){
    vis[node]=true;
    disc[node]=low[node]=timer++;
    
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,disc,low,timer,vis,adj,result);
            //while returning check for a shorter path
            low[node]=min(low[node],low[nbr]);
            
            //check bridge
            if(low[nbr]>disc[node]){  //nbr can only come after parent
                vector<int>ans;
                ans.push_back(nbr);
                ans.push_back(node);
                result.push_back(ans);
                
            }
             
        }
        else{
            //nbr is already visited and not parent
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
      vector<int>adj[n];
 
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>disc(n,-1);
    vector<bool>vis(n,false);
    vector<int>low(n,-1);
    int parent=-1;
    int timer=0;
    vector<vector<int>>result;
    //dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,parent,disc,low,timer,vis,adj,result);
        }
    }
    return result;
    }
};