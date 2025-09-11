class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());  
    int longest = 0;

    for (int num : st) {
        if (st.find(num - 1) == st.end()) {
            int currNum = num;
            int currStreak = 1;

            while (st.find(currNum + 1) != st.end()) {
                currNum++;
                currStreak++;
            }
            longest = max(longest, currStreak);
        }
    }
    return longest;
}

};