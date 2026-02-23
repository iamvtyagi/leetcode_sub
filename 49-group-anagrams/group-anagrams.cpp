class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string ,vector<string>> mp;
        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }

        for(auto& el : mp){
            ans.push_back(el.second);
        }
        return ans;
    }
};