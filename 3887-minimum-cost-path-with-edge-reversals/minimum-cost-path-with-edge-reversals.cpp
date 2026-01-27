class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            adj[u].push_back({v, w});       
            adj[v].push_back({u, 2*w});     
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);

        using T = pair<long long,int>; 
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost != dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                long long nc = cost + w;
                if (nc < dist[v]) {
                    dist[v] = nc;
                    pq.push({nc, v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};