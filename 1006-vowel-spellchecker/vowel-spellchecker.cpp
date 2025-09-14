class Solution {
public:
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string makeVowelInsensitive(string s, unordered_set<char>& st) {
        for (int i = 0; i < s.size(); i++) {
            if (st.find(s[i]) != st.end()) {
                s[i] = '*';
            } else {
                s[i] = tolower(s[i]);
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        int m = queries.size();
        unordered_set<char> st({'a','e','i','o','u','A','E','I','O','U'});
        vector<string> ans;

        // Direct exact match set
        unordered_set<string> exactSet(wordlist.begin(), wordlist.end());

        // Case-insensitive map (lowercase -> original word)
        unordered_map<string, string> caseMap;

        // Vowel-insensitive map (pattern -> original word)
        unordered_map<string, string> vowelMap;

        for (auto& w : wordlist) {
            string lower = toLowerCase(w);
            if (!caseMap.count(lower)) caseMap[lower] = w;

            string vowelPattern = makeVowelInsensitive(w, st);
            if (!vowelMap.count(vowelPattern)) vowelMap[vowelPattern] = w;
        }

        for (auto& q : queries) {
            // 1. Exact match
            if (exactSet.count(q)) {
                ans.push_back(q);
                continue;
            }

            // 2. Case-insensitive match
            string lowerQ = toLowerCase(q);
            if (caseMap.count(lowerQ)) {
                ans.push_back(caseMap[lowerQ]);
                continue;
            }

            // 3. Vowel-insensitive match
            string vowelQ = makeVowelInsensitive(q, st);
            if (vowelMap.count(vowelQ)) {
                ans.push_back(vowelMap[vowelQ]);
                continue;
            }

            // 4. No match
            ans.push_back("");
        }

        return ans;
    }
};
