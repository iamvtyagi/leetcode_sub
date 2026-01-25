class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        long long revNo = 0;
        while(n){
            int digit = n%10;
            revNo = revNo*10 + digit;
            n = n/10;
        }
        return (revNo==x)?true:false;
    }
};





