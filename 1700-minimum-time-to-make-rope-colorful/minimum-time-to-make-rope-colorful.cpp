class Solution {
public:
    int minCost(string nums, vector<int>& neededTime) {
        int n = nums.size();
        if(n==1) return 0;
        int cost = 0;
        int i = 0;
        int j = 1;
        while(j<n && i<n){
            if(nums[i]-'0' == nums[j]-'0'){
                if(neededTime[i]>neededTime[j]){
                    cost += neededTime[j];
                    neededTime[j]= -1;
                    j++;
                }else{
                    cost += neededTime[i];
                    j++;
                    i = j-1;
                }
            }else{
                i++;
                while(neededTime[i]==-1){
                    i++;
                }
                j++;
                // if(i==j) j++;
            }
        }
        return cost;
    }
};