class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<vector<int>> ans;
        int minDiff = abs(arr[1] - arr[0]);

        ans.push_back({arr[0], arr[1]});

        for (int i = 1; i < n - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);

            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            } else if (diff == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};