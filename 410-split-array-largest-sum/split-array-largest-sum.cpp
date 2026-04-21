class Solution {
public:
    bool isValid(const vector<int>& weights, long long shipCapacity, int days){
        int calculatingDays = 1, capacity = 0;
        for(const int weight : weights) {
            if(capacity + weight > shipCapacity) {
                ++calculatingDays;
                capacity = weight;
            }
            else capacity += weight;
            if(calculatingDays > days) return false;
        }
        return true;
    }
    int splitArray(vector<int>& weights, int days) {
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0); // gives sum of all values of arr
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(weights, mid, days)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};