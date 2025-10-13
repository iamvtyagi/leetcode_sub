class Solution {
public:
    void dfs(vector<vector<int>>& image , int i , int j , int newCol , int inCol,vector<int> &delRow , vector<int>& delCol){
           image[i][j] = newCol;
           int m = image.size();
           int n = image[0].size();
           for(int k = 0;k<4;k++){
                int nrow = delRow[k] + i;
                int ncol = delCol[k] + j;
                if(nrow>=0 && nrow < m && ncol>=0 && ncol<n && image[nrow][ncol] == inCol  && image[nrow][ncol] != newCol){
                        dfs(image,nrow,ncol,newCol , inCol , delRow, delCol);
                }
            }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<int> delRow({-1,0,+1,0});
        vector<int> delCol({0,+1,0,-1});
        if(sr >= m ||sc >= n) return {};
        int incol = image[sr][sc];
        vector<vector<int>> res;
        dfs(image,sr,sc,color,incol,delRow,delCol);
        return image;
    }
};