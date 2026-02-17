class Solution {
public:
    int findGCD(long long a, long long b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

    long long findLCM(long long a, long long b) {
        long long g = findGCD(a, b);
        if (a > LLONG_MAX / (b / g))
            return LLONG_MAX;

        return a * (b / g);
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            long long gcd = nums[i];
            long long lcm = nums[i];
            long long prod = 1;

            for(int j = i; j < n; j++) {

                gcd = findGCD(gcd, nums[j]);

                long long newLCM = findLCM(lcm, nums[j]);
                if (newLCM == LLONG_MAX) break;
                lcm = newLCM;

                if (prod > LLONG_MAX / nums[j])
                    break;
                prod *= nums[j];

                if (gcd != 0 && lcm > LLONG_MAX / gcd)
                    break;

                if (prod == gcd * lcm)
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};
