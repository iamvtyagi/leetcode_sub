class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        stack<int> s;
        unordered_map<int,int> mp;

        //fill v with next greater to right
        // start from the right loop mei kyuki yrr sbse phele right greate mei left el check hona hai 
        for(int i = m - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            if(s.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        for(int i = 0;i<n;i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};