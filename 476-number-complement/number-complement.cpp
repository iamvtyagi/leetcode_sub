class Solution {
public:
int helper(int n) {
    int cnt = 0;
    while (n) {
        cnt = cnt + 1; // add last bit
        n = n >> 1;          // shift right
    }
    return cnt;
}

    int findComplement(int num) {
        int noOfBits = helper(num);
        // cout<<noOfBits<<endl;
        int ans =  (pow(2,noOfBits)-1) - num;
        // if(ans<0) return -1*ans;
        return ans;
    }
};