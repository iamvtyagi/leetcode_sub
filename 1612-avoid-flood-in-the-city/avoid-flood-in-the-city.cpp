class Solution {
public:
    int bSearch(int lastRainDay, int currentDay, vector<int>& zeros) {
        int l = 0, r = zeros.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (zeros[mid] > lastRainDay && zeros[mid] < currentDay) {
                ans = mid;
                r = mid - 1;
            } else if (zeros[mid] <= lastRainDay) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp;
        vector<int> zeros;
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (rains[i] != 0) {
                int lake = rains[i];
                ans[i] = -1;
                if (mp.find(lake) != mp.end()) {
                    int lastRainDay = mp[lake];
                    int idx = bSearch(lastRainDay, i, zeros);
                    if (idx == -1) return {};
                    int dryDay = zeros[idx];
                    ans[dryDay] = lake;
                    zeros.erase(zeros.begin() + idx);
                }
                mp[lake] = i;
            } else {
                zeros.push_back(i);
            }
        }
        return ans;
    }
};
