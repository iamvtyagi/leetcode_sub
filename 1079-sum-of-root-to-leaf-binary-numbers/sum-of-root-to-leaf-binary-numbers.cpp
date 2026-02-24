class Solution {
public:
    void PreOrder(TreeNode* root, vector<string>& res,string curr){
        if(root==NULL) return;
        if( root->left==NULL && root->right == NULL){
            string ch = to_string(root->val);
            curr += ch;
            res.push_back(curr);
            return ;
        }
        string ch = to_string(root->val);
        PreOrder(root->left, res, curr+ch);
        PreOrder(root->right,res, curr+ch);

    }
    int sumRootToLeaf(TreeNode* root) {
        TreeNode* temp = root;
        vector<string> res;
        PreOrder(temp,res,"");
         int sum = 0;

         for(int i = 0;i<res.size();i++){
            string s = res[i];
            int curr = 0;
            for(int j = s.size()-1;j>=0;j--){
                int val = s[j] - '0';
                curr += val * pow(2,s.size()-j-1);
            }
            cout<<curr<<" ";
            sum += curr;
         }

        return sum;

    }
};