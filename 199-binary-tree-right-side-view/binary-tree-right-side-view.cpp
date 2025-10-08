class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        queue<TreeNode*> qt;
        qt.push(root);
        TreeNode* node;
        while(!qt.empty()){
             int n = qt.size();
             while(n--){
                 node = qt.front();
                 qt.pop();
                 if(node->left != NULL) qt.push(node->left);
                 if(node->right != NULL) qt.push(node->right);
             }
             ans.push_back(node->val);
        }
        return ans;
    }
};