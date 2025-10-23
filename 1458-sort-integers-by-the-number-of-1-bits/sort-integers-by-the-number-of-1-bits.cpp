class Solution {
public:
    static int countBits(int x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }

    static bool customCompare(int a, int b) {
        int bitsA = countBits(a);
        int bitsB = countBits(b);

        if (bitsA == bitsB)
            return a < b;       
        return bitsA < bitsB;    
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), customCompare);
        return arr;
    }
};