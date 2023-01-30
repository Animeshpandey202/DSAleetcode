class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& edges) {
        vector<int>adj[N];
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[v].push_back(u);
        }
        
        // run kahns algo
        vector<int>id(N,0);
        
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                
                id[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                id[it]--;
                if(id[it]==0){
                    q.push(it);
                }
                
                
            }
        }
        if(topo.size()==N)return topo;
        return {};
    }
};