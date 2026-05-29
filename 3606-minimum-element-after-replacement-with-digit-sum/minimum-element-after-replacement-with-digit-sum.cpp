class Solution {
public:
    int minElement(vector<int>& nums) {

        int minEle = INT_MAX;

        for (int x : nums) {

            int sum = 0;

            while (x > 0) {
                int digit = x % 10;  // Extract last digit
                sum += digit;        // Add digit to sum
                x /= 10;             // Remove last digit
            }

            minEle = min(minEle, sum);
        }

        return minEle;
    }
};