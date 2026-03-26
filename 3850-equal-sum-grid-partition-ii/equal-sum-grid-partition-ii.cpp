class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                totalSum += grid[i][j];
        
        unordered_set<long long> s;
        long long value = 0;
        
        for(int i = 0; i < m-1; i++) {
            for(int j = 0; j < n; j++) {
                value += grid[i][j];
                s.insert(grid[i][j]);
            }
            long long diff = 2*value - totalSum;
            if(diff == 0) return true;
            
            int topRows = i + 1;
            if(diff > 0) {
                if(topRows == 1 || n == 1) {
                    if(grid[0][0]==diff || grid[0][n-1]==diff || 
                       grid[i][0]==diff || grid[i][n-1]==diff)
                        return true;
                } else {
                    if(s.count(diff)) return true;
                }
            }
        }
        
        s.clear(); value = 0;

        for(int i = m-1; i >= 1; i--) {
            for(int j = 0; j < n; j++) {
                value += grid[i][j];
                s.insert(grid[i][j]);
            }
            long long diff = 2*value - totalSum;
            if(diff == 0) return true;
            
            int botRows = m - i;
            if(diff > 0) {
                if(botRows == 1 || n == 1) {
                    if(grid[m-1][0]==diff || grid[m-1][n-1]==diff || 
                       grid[i][0]==diff || grid[i][n-1]==diff)
                        return true;
                } else {
                    if(s.count(diff)) return true;
                }
            }
        }
        
        s.clear(); value = 0;
        
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m; j++) {
                value += grid[j][i];
                s.insert(grid[j][i]);
            }
            long long diff = 2*value - totalSum;
            if(diff == 0) return true;
            
            int leftCols = i + 1;
            if(diff > 0) {
                if(leftCols == 1 || m == 1) {
                    if(grid[0][0]==diff || grid[m-1][0]==diff || 
                       grid[0][i]==diff || grid[m-1][i]==diff)
                        return true;
                } else {
                    if(s.count(diff)) return true;
                }
            }
        }
        
        s.clear(); value = 0;
        
        for(int i = n-1; i >= 1; i--) {
            for(int j = 0; j < m; j++) {
                value += grid[j][i];
                s.insert(grid[j][i]);
            }
            long long diff = 2*value - totalSum;
            if(diff == 0) return true;
            
            int rightCols = n - i;
            if(diff > 0) {
                if(rightCols == 1 || m == 1) {
                    if(grid[0][n-1]==diff || grid[m-1][n-1]==diff || 
                       grid[0][i]==diff || grid[m-1][i]==diff)
                        return true;
                } else {
                    if(s.count(diff)) return true;
                }
            }
        }
        
        return false;
    }
};