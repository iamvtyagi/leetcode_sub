class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> v(n + 1, 0);

        for(int &k : nums){
            if(k < 1 || k > n) return false;
            v[k]++;
        }

        if(v[n] != 2) return false;

        for(int i = 1; i < n; i++){
            if(v[i] != 1) return false;
        }

        return true;
    }
};