class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        stk.push(nums[0]);
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            while (!stk.empty()) {
                if (gcd(stk.top(), curr) > 1) {
                    int val = stk.top();
                    stk.pop();
                    curr = lcm(val, curr);
                } else {
                    stk.push(curr);
                    break;
                }
            }
            if (stk.empty()) stk.push(curr); // ensure curr is pushed
        }
        vector<int> ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
