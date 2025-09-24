class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
                cout<<target<<" ";

        while(target > startValue){
            if(target%2 != 0){
                target += 1;
                cout<<target<<" ";
            }
            else{
                target /= 2;
                cout<<target<<" ";
            }
            steps++;
        }
        if(target == startValue){
            return steps;
        }
        // target *= 2;
        steps += abs(target-startValue);
        return steps;
    }
};