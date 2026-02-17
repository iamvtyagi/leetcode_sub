class Solution {
public:
    int helper(vector<int>& nums,int k){
        int mini = INT_MAX;
        int n = nums.size();
        int sum = 0;
        int i = 0;
        int j = 0;

        while(j<n){
            sum += nums[j];

            if(j-i+1 < k){
                j++;
            }
            else{
                // mini = min(mini,sum);
                if(sum>0){
                    if(mini>sum) mini = sum;
                }
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return mini;
    }

    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int ans = INT_MAX;

        for(int k = l; k <= r; k++){
            int a = helper(nums,k);
            if(a>0){
                if(ans>a) ans = a;
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};
