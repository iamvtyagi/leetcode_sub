class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<int>& curr, vector<vector<int>>& res, int sum) {
        if (root == NULL) return;

        curr.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                res.push_back(curr);
            }
        }

        helper(root->left, targetSum, curr, res, sum);
        helper(root->right, targetSum, curr, res, sum);

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        vector<int> curr;
        helper(root,targetSum,curr , res,0);
        return res;
    }
};