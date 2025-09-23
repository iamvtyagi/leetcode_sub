class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
         n = __builtin_popcount(n); 
        if(n==1) return true;
        return false;
    }
};