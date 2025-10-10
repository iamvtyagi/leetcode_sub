class Solution {
public:
   int countOfNodes(TreeNode* root){
      if(root == NULL) return 0;
      return 1 + countOfNodes(root->left) + countOfNodes(root->right);
   }
   
    bool dfs(TreeNode* root , int i , int total){
         if(root == NULL) return true;
         if(i > total ) return false;
         return dfs(root->left , 2*i , total) && dfs(root->right, 2*i + 1 , total);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = countOfNodes(root);
        int i = 1;
        return dfs(root,i,n); 
    }
};

// treated cbt as an array like in heap we treat array as heap 