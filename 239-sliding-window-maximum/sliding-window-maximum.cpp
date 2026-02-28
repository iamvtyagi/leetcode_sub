class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // stores indices
        vector<int> ans;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(j < n) {
            while(!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            // Remove elements out of window
            if(dq.front() < i) {
                dq.pop_front();
            }

            // Window size < k
            if(j - i + 1 < k) {
                j++;
            }
            else {  // window size == k

                ans.push_back(nums[dq.front()]);

                i++;
                j++;
            }
        }

        return ans;
    }
};