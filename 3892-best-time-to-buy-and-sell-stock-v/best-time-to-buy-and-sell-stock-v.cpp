class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, LLONG_MIN)));

        dp[0][0][0] = 0;

        for (int day = 0; day < n; ++day) {
            for (int txn = 0; txn <= k; ++txn) {
                for (int state = 0; state < 3; ++state) {
                    if (dp[day][txn][state] == LLONG_MIN) continue;

                    dp[day + 1][txn][state] = max(dp[day + 1][txn][state], dp[day][txn][state]);

                    if (state == 0 && txn < k) {
                        dp[day + 1][txn][1] = max(dp[day + 1][txn][1], dp[day][txn][0] - prices[day]);
                        dp[day + 1][txn][2] = max(dp[day + 1][txn][2], dp[day][txn][0] + prices[day]);
                    } else if (state == 1) {
                        dp[day + 1][txn + 1][0] = max(dp[day + 1][txn + 1][0], dp[day][txn][1] + prices[day]);
                    } else if (state == 2) {
                        dp[day + 1][txn + 1][0] = max(dp[day + 1][txn + 1][0], dp[day][txn][2] - prices[day]);
                    }
                }
            }
        }

        long long maxProfit = 0;
        for (int txn = 0; txn <= k; ++txn) {
            maxProfit = max(maxProfit, dp[n][txn][0]);
        }

        return maxProfit;
    }
};
