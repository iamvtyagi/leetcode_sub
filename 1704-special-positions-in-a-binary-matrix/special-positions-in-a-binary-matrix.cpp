class Solution {
public:
    bool checkRow(vector<vector<int>>& mat,int r,int c){
        for(int j = 0;j<mat[0].size();j++){
            if(j==c) continue;
            if(mat[r][j]==1) return true;
        }
        return false;
    }
    bool checkCol(vector<vector<int>>& mat,int r,int c){
        for(int j = 0;j<mat.size();j++){
            if(j==r) continue;
            if(mat[j][c]==1) return true;
        }
        return false;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j =  0;j<m;j++){
                if(mat[i][j]==1){
                    bool a = checkRow(mat,i,j);
                    bool b = checkCol(mat,i,j);
                    if(!a && !b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};