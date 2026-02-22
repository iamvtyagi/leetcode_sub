class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(maxDepth(root->left) , maxDepth(root->right));
    }
    TreeNode* dfs(TreeNode* root,int n,int d){
        if(root == NULL) return NULL;
        if(d >= n-1) return root;
       TreeNode* left =  dfs(root->left,n,d+1);
       TreeNode* right =  dfs(root->right,n,d+1);
       if (left && right) return root;
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int n = maxDepth(root);
        TreeNode* node = dfs(root,n,0);
        return node;
    }
};