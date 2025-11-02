class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
            st.insert(nums[i]);
        }
        for(int el = mini+1;el<maxi;el++){
            if(st.find(el) == st.end()){
                ans.push_back(el);
            }
        }
        return ans;
    }
};