class Solution {
public:
    int bsearch(vector<int>& nums, int val, int l, int r){
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] > val){
                ans = mid;    
                l = mid + 1;   
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                idx = i-1;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int val = nums[idx];
        int i = bsearch(nums,val,idx+1,n-1);
        swap(nums[i],nums[idx]);
        reverse(nums.begin()+idx+1,nums.end());
    }
};