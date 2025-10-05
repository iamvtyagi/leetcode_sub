class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minValue = INT_MAX;
        int minAns = -1;
        for(int i = 0;i<n;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+ nums[l] + nums[r];
                 if(nums[i]+ nums[l] + nums[r] > target){
                    if(minValue < abs(sum-target)){
                         r--;
                    }else{
                        minValue = min(minValue,abs(sum-target));
                        minAns = sum;
                        r--;
                    }
                    //  r--;
                 }else if(sum < target){ 
                    if(minValue < abs(sum-target)){
                        //  r--;
                        l++;
                    }else{
                        minValue = min(minValue,abs(sum-target));
                        minAns = sum;
                        // r--;
                        l++;
                    }    
                 }else{
                    return sum;
                 }
            }
        }
        return minAns;
    }
};