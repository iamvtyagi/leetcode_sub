class Solution {
public:
    bool check(int n){
        while(n > 0){
            int digit = n%10;
            if(digit == 0){
                 return false;
            }
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<=n-1;i++){
            if(check(i) && check(n-i)){
                 return {i,n-i};
            }
        }
        return {};
    }
};