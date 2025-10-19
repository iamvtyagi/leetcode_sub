class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int small = k;
        int n= nums.size();
        unordered_set<int> st(nums.begin(),nums.end());

        while(true){
            if(st.find(small) == st.end()){
                return small;
            }else{
                small += k;
            }
        }
        return -1;
    }
};