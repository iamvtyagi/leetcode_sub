class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        // loop until length <= k
        while (n > k) {
            string t = "";              
            for (int j = 0; j < n; j += k) {    // non-overlapping groups starting at 0
                int sum = 0;
                for (int l = j; l < j + k && l < n; l++) {
                    sum += (s[l] - '0');     
                }
                t += to_string(sum);       
            }
            s = t;
            n = s.size();         
        }
        return s; 
    }
};
