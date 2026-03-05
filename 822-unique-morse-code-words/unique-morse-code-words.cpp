class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> transformation{
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> ans;
        for(int i = 0;i<words.size();i++){
            string word = "";
            for(int j = 0;j<words[i].size();j++){
                 int idx = words[i][j] - 'a';
                 word += transformation[idx];
            }
            ans.insert(word);
        }
        return ans.size();
    }
};