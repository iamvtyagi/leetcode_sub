class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto el : mp) {
            minh.push({el.second, el.first});  
            if(minh.size() > k) minh.pop();    
        }

        vector<int> ans;
        while(!minh.empty()) {
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};
