class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int left = numBottles % numExchange;
        int neww = numBottles / numExchange;
        ans += neww;
        int el = left + neww ;
        ans += el /numExchange;
        neww = el /numExchange;
        left = el%numExchange;
        el = left + neww;
        while(el >= numExchange){
             ans += el/numExchange;
            neww = el /numExchange;
           left = el%numExchange;
            el = left + neww;
        }
        return ans;
    }
};