class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        long long rvs = stoll(s);
        int val = n-rvs;
        return abs(val);
    }
};