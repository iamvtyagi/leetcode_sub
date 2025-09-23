class Solution {
public:
    bool isPowerOfThree(int n) {
         while(n > 1){
             int a = n%3;
             if(a != 0) return false;
             n = n/3;
         }
         if(n==1) return true;
         return false;
    }
};