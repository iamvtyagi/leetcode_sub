class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (auto& el : nums) {
            st.insert(el);
        }

        if (st.size() < 3) {
            return *st.rbegin();
        } else {
            auto it = st.rbegin();
            advance(it, 2);     
            return *it;
        }
    }
};
