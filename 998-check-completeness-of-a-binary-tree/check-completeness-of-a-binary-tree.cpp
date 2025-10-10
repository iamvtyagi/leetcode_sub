class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        bool past = false;
        while(!qt.empty()){
            TreeNode* node = qt.front();
            qt.pop();
            if(node==NULL) past = true;
            else {
                if(past==true){
                    return false;
                }else{
                    qt.push(node->left);
                    qt.push(node->right);
                }
            }
        }
        return true;
    }
};