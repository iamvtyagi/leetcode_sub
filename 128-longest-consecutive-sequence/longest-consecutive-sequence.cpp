class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int ans = 1;
        int fans = 1;
        for(int i = 1;i<n;i++){
            if(nums[i-1]+1 == nums[i]){
                 ans+=1;
                 fans = max(fans,ans);
            }else if(nums[i-1] != nums[i]){
                  ans = 1;
            }
        }
        return fans;
    }
};