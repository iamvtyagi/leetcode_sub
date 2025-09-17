class Solution {
public:
  vector<int> dp;
int helper(int n ){
    if(n<=1) return n;
    if(n==2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n-1)+helper(n-2) + helper(n-3);
}
    int tribonacci(int n) {
        dp = vector<int>(38,-1);
        return helper(n);
    }
};