class Solution {
public:
    int reverse(int x) {
        int n = x;
        long long revNo = 0;
        while(n){
            int digit = n%10;
            revNo = revNo *10 + digit;
            n = n/10;
        }
        if(revNo > INT_MAX || revNo <INT_MIN) return 0;
        return revNo;
    }
};
