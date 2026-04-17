class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);
            mp[temp].push_back(i);
        }
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            string a = to_string(nums[i]);
            reverse(a.begin(), a.end());
            int j = 0;
            while (j < a.size()) {
                if (a[j] == '0')
                    j++;
                else
                    break;
            }
            string b = "";
            while (j < a.size()) {
                b += a[j];
                j++;
            }
            vector<int>& temp = mp[b];
            int s = 0;
            int e = temp.size() - 1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (temp[mid] <= i) {
                    s = mid + 1;
                } else {
                    int diff = temp[mid] - i;
                    ans = min(ans, diff);
                    e = mid - 1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};