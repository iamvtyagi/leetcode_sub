class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
         vector<int> arr;
        long long ans = 1;
        arr.push_back(ans); // First element is always 1

        for(int i = 1; i < n; i++) {
            ans = 1LL * ans * (n - i);
            ans = ans / i;
            arr.push_back(ans);
        }
        return arr;       
    }
};