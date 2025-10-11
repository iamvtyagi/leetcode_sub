class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int> , greater<int>> minh;

        for(int i = 0;i<n;i++){
             if(minh.size()<k){
                 minh.push(nums[i]);
             }else{
                minh.push(nums[i]);
                minh.pop();
             }
        }
        return minh.top();
    }
};