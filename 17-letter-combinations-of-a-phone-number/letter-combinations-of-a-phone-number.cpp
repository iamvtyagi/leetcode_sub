class Solution {
public:
    void helper(string dig,int idx,unordered_map<char,string>& mp,string curr,vector<string>& res){
        if(idx == dig.size()){
            res.push_back(curr);
            return;
        }

        char currDig = dig[idx];
        string currChar = mp[currDig];

        for(int i = 0;i<currChar.size();i++){

           curr.push_back(currChar[i]);
            helper(dig,idx+1,mp,curr,res);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};  
        
        unordered_map<char,string> numSeq;
        numSeq['2'] = "abc";
        numSeq['3'] = "def";
        numSeq['4'] = "ghi";
        numSeq['5'] = "jkl";
        numSeq['6'] = "mno";
        numSeq['7'] = "pqrs";
        numSeq['8'] = "tuv";
        numSeq['9'] = "wxyz";

        vector<string> res;
        helper(digits , 0, numSeq,"",res);
        return res;
    }
};