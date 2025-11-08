class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for(auto& el : candyType){
            st.insert(el);
        }
        if(st.size() >= n/2) return n/2;
        return st.size();
    }
};