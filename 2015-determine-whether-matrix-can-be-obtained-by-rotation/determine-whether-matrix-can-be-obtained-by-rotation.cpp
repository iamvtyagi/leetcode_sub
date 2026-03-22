class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> mat1 = mat, mat2 = mat, mat3 = mat;

        auto rotate90 = [&](vector<vector<int>>& who, vector<vector<int>>& wrt) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    who[j][n-i-1] = wrt[i][j];
                }
            }
        };

        rotate90(mat1, mat);
        rotate90(mat2, mat1);
        rotate90(mat3, mat2);

        return mat == target || mat1 == target || mat2 == target || mat3 == target;
    }
};