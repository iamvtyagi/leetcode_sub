class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto &el : patterns) {
            if (word.find(el) != string::npos)
                cnt++;
        }
        return cnt;
    }
};