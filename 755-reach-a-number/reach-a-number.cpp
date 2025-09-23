class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);   // symmetry
        long long sum = 0;
        int step = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            step++;
            sum += step;
        }

        return step;
    }
};

// if sum-target is even than only we can achieve our target because let say diff is 8 
// than we will always have numbers jinko flip krke target pe phuch jaunga 
// and maanlo ham i ko flip krre h to ham sum mei se 2*i minus krre h actual mei 
// kyuki phele vo plus krre the ek vo nuksan and ab ham usko minus upar se krege 
