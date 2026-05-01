class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long n = nums.size();
        long ts = 0;    // Total Sum
        long prev = 0;  // F(0)
        
        for(int i = 0; i < n; i++){
            prev += (long)i * nums[i];
            ts += nums[i];
        }
        
        long maxi = prev; // Shuruat mein F(0) hi max hai
        
        for(int i = 1; i < n; i++){
            // Formula: F(i) = F(i-1) + TotalSum - n * last el of prvs rotation
            long curr = prev + ts - n * (long)nums[n - i];
            maxi = max(maxi, curr);
            prev = curr;
        }
        
        return (int)maxi;
    }
};