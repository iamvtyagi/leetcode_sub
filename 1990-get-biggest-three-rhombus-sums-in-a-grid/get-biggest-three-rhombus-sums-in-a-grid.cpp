class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0)); // ↘ diagonal
        vector<vector<int>> da(m, vector<int>(n, 0)); // ↙ anti-diagonal

        // Build prefix sums
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = grid[i][j];
                if(i > 0 && j > 0) dp[i][j] += dp[i-1][j-1];

                da[i][j] = grid[i][j];
                if(i > 0 && j < n-1) da[i][j] += da[i-1][j+1];
            }
        }

        auto diag = [&](int r1, int c1, int r2, int c2){
            int res = dp[r2][c2];
            if(r1 > 0 && c1 > 0) res -= dp[r1-1][c1-1];
            return res;
        };

        auto anti = [&](int r1, int c1, int r2, int c2){
            int res = da[r2][c2];
            if(r1 > 0 && c1 < n-1) res -= da[r1-1][c1+1];
            return res;
        };

        set<int> res;

        auto add_top3 = [&](int val){
            res.insert(val);
            if(res.size() > 3) res.erase(res.begin());
        };

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                add_top3(grid[r][c]); 

                for(int k = 1; k < min(m, n); k++){
                    if(r-k < 0 || r+k >= m || c-k < 0 || c+k >= n) break;

                    int s =
                        diag(r-k, c, r, c+k) +
                        diag(r, c-k, r+k, c) +
                        anti(r-k, c, r, c-k) +
                        anti(r, c+k, r+k, c)
                        - grid[r-k][c]
                        - grid[r][c+k]
                        - grid[r+k][c]
                        - grid[r][c-k];

                    add_top3(s);
                }
            }
        }

        vector<int> ans(res.rbegin(), res.rend());
        return ans;
    }
};