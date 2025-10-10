class Solution {
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis,int delRow[],int delCol[]){
        int n = grid.size();
        int m = grid[0].size();
         queue<pair<int,int>> qt;
         qt.push({row,col});
         vis[row][col] = 1;
         while(!qt.empty()){
             
             int r = qt.front().first;
             int c = qt.front().second;
             
             qt.pop();
               for(int i = 0;i<4;i++){
                         int nrow = delRow[i] + r;
                         int ncol = delCol[i] + c;
                         if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                               vis[nrow][ncol] = 1;
                               qt.push({nrow,ncol});
                         }
              }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1 , 0 , 1, 0};
        int delCol[] = {0,1,0,-1};
      vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
             for(int j = 0;j<m;j++){
                  if(grid[i][j] == '1' && !vis[i][j]){
                      cnt++;
                       bfs(i,j,grid,vis,delRow,delCol);
                  }
             }
        }
        return cnt;        
    }
};