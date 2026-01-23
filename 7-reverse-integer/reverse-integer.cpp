class Solution {
public:
    int reverse(int n) {
        long long x = n;
        long long rev = 0;
        bool check = false;
        if(x<0) check = true;
        if(check) x = -1 * x;
        while(x>0){
            int digit = x%10;
            rev = rev * 10 + digit;
            x = x/10;
        }
        if(rev > INT_MAX) return 0;
        if(check) return -1 * rev;
        return rev;
    }
};