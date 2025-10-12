class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long shiftSum = 0;
        int n = s.size();
        
        for (int i = n - 1; i >= 0; i--) {
            shiftSum = (shiftSum + shifts[i]) % 26;  
            s[i] = (s[i] - 'a' + shiftSum) % 26 + 'a';
        }

        return s;
    }
};
