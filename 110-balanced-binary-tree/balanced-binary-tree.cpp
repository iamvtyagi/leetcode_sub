/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(root->left != NULL) leftHeight++;
        if(root->right != NULL) rightHeight++;
        int diff = leftHeight - rightHeight;
        if(diff < 0) diff = -diff;
        if(diff>1){
           return false;
        }
        return (isBalanced(root->right) && isBalanced(root->left));
    }
};