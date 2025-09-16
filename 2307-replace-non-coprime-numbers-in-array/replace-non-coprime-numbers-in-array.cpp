class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for (int num : nums) {
            while (!stk.empty() && gcd(stk.back(), num) > 1) {
                num = lcm(stk.back(), num);
                stk.pop_back();
            }
            stk.push_back(num);
        }
        return stk;
    }
};
