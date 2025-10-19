class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0;i<n;i++){
            unordered_set<int> evenst;
            unordered_set<int> oddst;
            for(int j = i;j<n;j++){
                if(nums[j]%2==0){
                    evenst.insert(nums[j]);
                }else{
                    oddst.insert(nums[j]);
                }
                if(evenst.size() == oddst.size()){
                    maxLen = max(maxLen,j-i+1);
                }
            }
            
        }
        return maxLen;
    }
};