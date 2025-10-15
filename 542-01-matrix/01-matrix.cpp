class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qt;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    qt.push({{i,j},0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!qt.empty()){
            int row = qt.front().first.first;
            int col = qt.front().first.second;
            int steps = qt.front().second;
            qt.pop();
            dist[row][col] = steps;
            for(int i = 0;i<4;i++){
                 int nrow = row + delRow[i];
                 int ncol = col + delCol[i];
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                      vis[nrow][ncol] = 1;
                      qt.push({{nrow,ncol},steps+1});
                 }
            }
        }
        return dist;        
    }
};