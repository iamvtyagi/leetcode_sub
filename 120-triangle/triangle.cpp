class Solution {
public:
   vector<vector<int>> dp;
    int helper(vector<vector<int>>& triangle,int i ,int j ,int n){
        if(j==n-1){
            return triangle[j][i];
        }
        if(dp[i][j] != INT_MIN){
             return dp[i][j];
        }
        return dp[i][j] =  triangle[j][i] + min(helper(triangle,i,j+1,n),helper(triangle,i+1,j+1,n));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
       dp =  vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN));
        return helper(triangle, 0, 0, n);
    }
};