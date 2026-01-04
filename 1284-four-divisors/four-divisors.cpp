class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            vector<int> hehe;
            for(int j = 1;j<=nums[i];j++){
                if(nums[i]%j==0){
                    hehe.push_back(j);
                    if(hehe.size()==4){
                        if(j != nums[i]){
                            break;
                        }else{
                            ans.push_back(hehe);
                        }
                    }
                } 
            }
        }
        int ryt = 0;
        for(int i = 0;i<ans.size();i++){
            int sum = accumulate(ans[i].begin(), ans[i].end(), 0);
            ryt += sum;
        }
        return ryt;
    }
};