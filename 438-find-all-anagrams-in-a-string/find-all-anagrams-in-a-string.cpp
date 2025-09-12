class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> ans;
        vector<int> freqP(26, 0), freqS(26, 0);


        for (char c : p) freqP[c - 'a']++;

        for (int i = 0; i < m; i++) {
            freqS[s[i] - 'a']++;
        }
        if (freqS == freqP) ans.push_back(0);

        for (int i = m; i < n; i++) {
            freqS[s[i] - 'a']++;               
            freqS[s[i - m] - 'a']--;           

            if (freqS == freqP) ans.push_back(i - m + 1);
        }
        return ans;
    }
};