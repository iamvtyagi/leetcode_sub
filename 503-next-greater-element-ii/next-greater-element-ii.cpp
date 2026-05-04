class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        for(int i = 0;i<n;i++){

            int el = nums[i];
            bool check = false;

            for(int j = i+1;j<(i+n);j++){
                if(nums[j%n] > el){
                    v.push_back(nums[j%n]);
                    check = true;
                    break;
                }
            }
            if(!check) v.push_back(-1);
        }
        return v;
    }
};