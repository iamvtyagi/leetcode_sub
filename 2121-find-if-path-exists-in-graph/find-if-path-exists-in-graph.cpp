class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , vector<int> &ans){
         ans.push_back(node);
         for(auto nbr : adj[node]){
            if(!vis[nbr]){
                 vis[nbr]= 1;
                 dfs(nbr,adj,vis,ans);
            }
         }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> vis(n,0);
         
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // for (int i = 0; i < adj.size(); i++) {
        //     cout << i << " -> ";
        //     for (int j = 0; j < adj[i].size(); j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vis[source] = 1;
        dfs(source,adj,vis,ans);
        // for(int i = 0;i<ans.size();i++){
        //       if(ans[i]==destination) return true;
        // }
        return vis[destination];
    }
};
