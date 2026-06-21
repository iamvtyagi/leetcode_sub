class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        int cnt = 0;
        sort(costs.begin(),costs.end());
        int i = 0;
        while(coins && i<n){
            if(costs[i] <= coins) {
                coins -= costs[i];
                i++;
                cnt++;
            }else break;
            
        }
        return cnt;
    }
};