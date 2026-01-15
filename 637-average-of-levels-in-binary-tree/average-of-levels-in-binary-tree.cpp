class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        vector<vector<int>> v;
        if(root == NULL) return {};

        queue<pair<TreeNode*,int>> qt;
        qt.push({root, 0});

        while(!qt.empty()) {
            TreeNode* node = qt.front().first;
            int idx = qt.front().second;
            qt.pop();

            if(idx == v.size()) {
                v.push_back({});
            }

            v[idx].push_back(node->val);

            if(node->left != NULL)
                qt.push({node->left, idx + 1});

            if(node->right != NULL)
                qt.push({node->right, idx + 1});
        }

        vector<double> ans;
        for(int i = 0; i < v.size(); i++) {
            double sum = 0;
            for(int j = 0; j < v[i].size(); j++) {
                sum += v[i][j];
            }
            ans.push_back(sum / v[i].size());
        }

        return ans;
    }
};
