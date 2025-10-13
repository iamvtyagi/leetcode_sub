#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> qt;

        // Step 1: Push all initially rotten oranges into the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    qt.push({{i,j},0});
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int tm = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        // Step 2: BFS traversal
        while(!qt.empty()){
            int r = qt.front().first.first;
            int c = qt.front().first.second;
            int t = qt.front().second;
            qt.pop();
            tm = max(tm, t);

            for(int i = 0; i < 4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    qt.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Step 3: Check if any fresh orange remains
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return tm;
    }
};
