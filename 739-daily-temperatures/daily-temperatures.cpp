class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();

        stack<pair<int,int>> s;
        vector<int> ans(n,0);

        for(int i = n-1;i>=0;i--){


            if(s.size() > 0 && s.top().first > nums[i] ){
                ans[i]= s.top().second - i;
            }else{
                while(s.size()>0 && s.top().first <= nums[i]){
                    s.pop();
                }

                if(s.size() > 0) ans[i] = s.top().second - i;
                 
            }
            s.push({nums[i],i});
        }
        return ans;
    }
};