class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    void dfs(vector<vector<int>>& grid, int i, int j, ll prod, int m, int n, vector<vector<vector<ll>>>& mem, ll& ans){
        prod *= grid[i][j];
        if(prod >= 0 && prod > mem[i][j][0]){
            mem[i][j][0] = prod;
        }
        else if(prod < 0 && prod < mem[i][j][1]){
            mem[i][j][1] = prod;
        }
        else{
            return;
        }
        if(i == m-1 && j == n-1){
            if(prod >= 0) ans = max(ans, prod);
        }
        if(i < m-1) dfs(grid, i+1, j, prod, m, n, mem, ans);
        if(j < n-1) dfs(grid, i, j+1, prod, m, n, mem, ans);
    }
    int maxProductPath(vector<vector<int>>& grid) {
        ll ans = -1;
        int m = grid.size();
        int n = grid[0].size();
        bool hasZero = false;
        vector<vector<vector<ll>>> mem(m, vector<vector<ll>>(n, vector<ll>(2, 0)));
        // 4^15=1073741824
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) hasZero = true;
                mem[i][j][0] = -1073741824 - 5; // max neg.
                mem[i][j][1] = 1073741824 + 5;  // max pos.
            }
        }
        dfs(grid, 0, 0, 1, m, n, mem, ans);
        return ans==-1?(hasZero?0:ans):(ans%MOD);
    }
};