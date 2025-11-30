class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        unordered_set<char> st;
        for(auto el : s){
            st.insert(el);
        }
        return st.size();
    }
};