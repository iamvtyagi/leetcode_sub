class Solution {
public:
     bool findi(TreeNode* a , TreeNode* b){
         if(a == NULL) return false;
         if(a->val == b->val) return true;
         return findi(a->left, b) || findi(a->right , b);
     }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val == p->val ) return p;
        if(root->val == q->val) return q;

        bool isp = findi(root->left,p);
        bool isq = findi(root->right , q);
        if((isp && isq) || (!isp && !isq)){
             return root;
        }else if(isp && !isq){
            return helper(root->left , p , q);
        }
        else{
            return helper(root->right , p , q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return helper(root, p , q);
    }
};