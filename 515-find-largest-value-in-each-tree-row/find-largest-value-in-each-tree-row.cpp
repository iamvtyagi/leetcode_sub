class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {}; 
        vector<vector<int>> hehe;
        vector<int> ans;;
        queue<pair<TreeNode*, int>> q;
       q.push({root, 0}); 
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (lvl == hehe.size())     
                hehe.push_back({});

            hehe[lvl].push_back(node->val);
            if(node->left != NULL){
                q.push({node->left,lvl+1});
            }
            if(node->right != NULL){
                q.push({node->right,lvl+1});
            }
        }
        int mx;
        for(int i = 0;i<hehe.size();i++){
            mx = INT_MIN;
            for(int j = 0;j<hehe[i].size();j++){
                if(mx < hehe[i][j]) mx = hehe[i][j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};