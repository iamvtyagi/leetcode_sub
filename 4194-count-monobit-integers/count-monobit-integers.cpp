class Solution {
    // bool checkNo(int n){
    //     int totalBits = 0;
    //     int temp = n;
    //     while (temp > 0) {
    //         totalBits++;
    //         temp = temp >> 1;   
    //     }   
    //     int ones = __builtin_popcount(n);
    //     int zeros = ones - totalBits;  
    //     if(!ones || !zeros) return true;
    //     return false;
    // }
public:
    int countMonobit(int n) {
        // int cnt = 0;
        // for(int i = 0;i<=n;i++){
        //     if(checkNo(i)) cnt++;
        // }
        // return cnt;
        return 1 + log2(n+1);
    }
};