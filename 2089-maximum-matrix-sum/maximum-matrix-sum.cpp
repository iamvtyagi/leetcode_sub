class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int cnt = 0;
        int cnt0 = 0;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] < 0 ) {
                    cnt++;
                }
                if(matrix[i][j]==0){
                    cnt0++;
                }
             mini = min(mini,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(cnt%2==0 || cnt0 >0){
            return sum;
        }
        return sum - (2*mini);
    }
};