class Solution {
public:
int t[1001];
int helper(int n ,vector<int>& cost ) {
        // base case 
        if(n==0 || n==1){
            return 0;
        }
        if(t[n] != -1){
            return t[n];
        }
        int oneStep = cost[n-1] + helper(n-1,cost);
        int twoStep = cost[n-2] + helper(n-2,cost);
        return t[n] =  min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t,-1,sizeof(t));
        return helper(n,cost);
    }
};