class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_set<char> st({'a','e','i','o','u','A','E','I','O','U'});
        
        vector<int> idx;
        vector<char> vowel;
        
        for (int i = 0; i < n; i++) {
            if (st.find(s[i]) != st.end()) {
                idx.push_back(i);
                vowel.push_back(s[i]);
            }
        }
        
        sort(vowel.begin(), vowel.end());
        
        for (int i = 0; i < idx.size(); i++) {
            s[idx[i]] = vowel[i];
        }
        
        return s;
    }
};
