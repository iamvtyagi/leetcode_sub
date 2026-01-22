class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int n = x;
        long long newNo = 0;
        int rem = 0;
        while(x){
            rem = x%10;
            newNo = newNo*10 + rem;
            x = x/10;
        }
        return (newNo==n)?true:false;
    }
};