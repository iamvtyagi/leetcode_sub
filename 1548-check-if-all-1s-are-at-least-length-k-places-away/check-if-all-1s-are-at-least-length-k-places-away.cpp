class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int l;
        for(int i = 0;i<n;i++){
            if(nums[i]==1){
                l=i;
                break;
            }
        }
        int cnt = INT_MAX;
        for(int i =l;i<n;i++){
            if(nums[i]==1){
                if(cnt<k){
                    return false;
                }
                cnt = 0;
            }else{
                cnt++;
            }
        }
        return true;
    }
};