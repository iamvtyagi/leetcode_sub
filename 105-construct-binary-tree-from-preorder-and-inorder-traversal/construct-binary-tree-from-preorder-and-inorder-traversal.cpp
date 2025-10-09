class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int start , int end , int &idx){
         if(start > end){
            return NULL;
         }
         int rootValue = preorder[idx];
         int i = start;
         for(;i<=end;i++){
            if(inorder[i] == rootValue){
                break;
            }
         }
         TreeNode* root = new TreeNode(rootValue);
         idx++;
         root->left = helper(preorder,inorder,start,i-1,idx);
         root->right = helper(preorder,inorder,i+1, end, idx);
         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return helper(preorder,inorder,0,n-1,idx);
    }
};