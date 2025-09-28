class Solution {
public:
    long long splitArray(vector<int>& nums) {
        bool right = true;
        int idx = 0;
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return llabs((long long)nums[0]-(long long)nums[1]);
        
        for(int i = 0;i<nums.size()-1;i++){
                 if(nums[i] < nums[i+1]){
                  idx = max(idx,i+1);
             }else{
                   break;
             }
        }
        cout<<idx<<endl;
        int idx2 = -1;
        if(idx >= 0  && idx+1<n-1){
        for(int i = idx+1;i<nums.size()-1;i++){
             if(nums[i] > nums[i+1]){
                  idx2 = max(idx2,i+1);
             }else{
                 right = false;
             }
        }             
        }
        
        if(!right) return -1;

        long long leftSum = 0;
        long long rightSum  = 0;
        if (idx >= 0){
                    for(int i = 0;i<=idx;i++){
                    leftSum += nums[i];
                }
        }
        if(idx+1 < n){
                    for(int i =idx+1;i<nums.size();i++){
                     rightSum += nums[i];
                }
        }
        long long ans = (idx >= 0 && idx < n )? min(llabs((leftSum-(long long)nums[idx]) - (rightSum+(long           long)nums[idx])) , llabs(leftSum - rightSum) ) :-1;
        return ans;
    }
};