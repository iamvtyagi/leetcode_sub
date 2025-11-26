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
    vector<int> findMode(TreeNode* root) {
        int mx = 0;
        unordered_map<int,int> mp;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* node = qt.front();
            qt.pop();
            mp[node->val]++;
            if(mp[node->val]>mx) mx = mp[node->val];
            if(node->left != NULL){
                qt.push(node->left);
            }
            if(node->right != NULL){
                qt.push(node->right);
            }
        }
        vector<int> ans;
        for(auto& el : mp){
            if(el.second == mx) ans.push_back(el.first);
        }
        return ans;
    }
};