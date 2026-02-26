class Solution {
public:
    void helper(vector<string>& res, int n, int open, int close, string curr) {
        
        if(curr.length() == 2*n) {
            res.push_back(curr);
            return;
        }

        if(open < n) {
            helper(res, n, open+1, close, curr + "(");
        }

        if(close < open) {
            helper(res, n, open, close+1, curr + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, 0, 0, "");
        return ans;
    }
};