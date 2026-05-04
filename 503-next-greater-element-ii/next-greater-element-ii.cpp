class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n, -1);

        for(int i = 2*n - 1;i>=0;i--){

            if(i>=n){

              if(s.size() > 0 && s.top() <= nums[i%n] ){
                    while(s.size() > 0 && s.top() <= nums[i % n]) {
                        s.pop();
                    }
                }


            }else{

                if(s.size()==0){
                    ans.push_back(-1);
                }else if(s.size() > 0 && s.top() <= nums[i%n]){
                    while(s.size() > 0 && s.top() <= nums[i%n]){
                        s.pop();
                    }

                    if(s.size() > 0){
                       ans[i] = s.top();
                    }
                }else{
                    ans[i] = s.top();
                }

            }

            s.push(nums[i%n]);
        }
        return ans;
    }
};