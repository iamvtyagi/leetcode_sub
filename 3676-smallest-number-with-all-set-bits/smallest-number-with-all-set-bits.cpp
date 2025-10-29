class Solution {
public:
   int cntOfBits(int n ){
    if(n==0) return 1;
    int cnt=0;
    while(n){
        cnt++;
        n >>= 1;
    }
    return cnt;
   }
   int noOfSetBits(int n){
    int cnt = 0;
    while(n){
        if(n&1){
            cnt++;
        }
        n >>= 1;
    }
    return cnt;
   }
    int smallestNumber(int n) {
        while(true){
            if(cntOfBits(n) == noOfSetBits(n)){
                  return n;
            }else{
                n++;
            }
        }
        return 69;
    }
};