class Solution {
public:
   bool helper(TreeNode* root,int val){
        if(root == NULL){
             return true;
        }
       if(root->val != val) return false;
       return helper(root->left,val) && helper(root->right,val);
   }
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return helper(root,val);
    }
};