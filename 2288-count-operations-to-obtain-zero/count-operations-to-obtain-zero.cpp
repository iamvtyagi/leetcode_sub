class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        while(num1 && num2){
            if(num1>=num2){
                int div=num1/num2;
                cnt+=div;
                num1=num1-div*num2;
            }else{
                int div=num2/num1;
                cnt+=div;
                num2=num2-div*num1;
            }
        }
        return cnt;
    }
};