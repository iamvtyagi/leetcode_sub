class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj,vector<int> &vis){
         for(auto nbr : adj[node]){
              if(!vis[nbr]){
                   vis[nbr] = 1;
                   dfs(nbr ,adj , vis);
              }
         }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adji(V);
        for(int i = 0;i<adj.size();i++){
             for(int j = 0;j<adj[i].size();j++){
                  if(adj[i][j]==1 && j != i){
                            adji[i].push_back(j);
                            adji[j].push_back(i);   
                  }
             }
        }
        
        int cnt = 0;
        vector<int> vis(V,0);
        for(int i = 0;i<V;i++){
            if (!vis[i]) {
                cnt++;
                vis[i] = 1;
                dfs(i, adji, vis);
            }
        }
        return cnt;        
    }
};