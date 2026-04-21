class Solution {
public:
    bool isValid(vector<int>& nums,int div,int k){
        int sum = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            sum += (nums[i] + div - 1) / div;

            if(sum > k){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int ans = r;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isValid(nums,mid,threshold)){
                r = mid-1;
                ans = min(ans,mid);
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};