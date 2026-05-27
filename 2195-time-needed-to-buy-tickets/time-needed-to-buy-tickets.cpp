class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        int i = 0;

        while(tickets[k] != 0){

            if(tickets[i] != 0) {
                ans++;
                tickets[i]--;
            }

            i = (i+1)%n;
        }
        return ans;
    }
};