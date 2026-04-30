class Solution {
public:
    int helper(vector<vector<int>> &grid,int n ,int m, int k , int i , int j,
               vector<vector<vector<int>>> &dp){

        // out of bounds or no cost left
        if(i>=n || j>=m || k < 0){
            return INT_MIN;
        }

        // destination
        if(i==n-1 && j==m-1){
            if(grid[i][j] > 0 && k <= 0) return INT_MIN;
            return grid[i][j];
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        // calculate new k (cost handling)
        int newK = k;
        if(grid[i][j] > 0) newK--;   // cost = 1 if >0

        // move right
        int right = helper(grid,n,m,newK,i,j+1,dp);

        // move down
        int down = helper(grid,n,m,newK,i+1,j,dp);

        int best = max(right, down);

        if(best == INT_MIN) return dp[i][j][k] = INT_MIN;

        return dp[i][j][k] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k+1, -1))
        );

        int ans = helper(grid,n,m,k,0,0,dp);

        return (ans == INT_MIN) ? -1 : ans;
    }
};