class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxi; // {value, index}
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n) {
            // push current element
            maxi.push({nums[j], j});

            // window size < k
            if(j - i + 1 < k) {
                j++;
            }
            else {  // window size == k
                // remove elements outside window
                while(!maxi.empty() && maxi.top().second < i) {
                    maxi.pop();
                }
                ans.push_back(maxi.top().first);
                i++;
                j++;
            }
        }
        return ans;
    }
};