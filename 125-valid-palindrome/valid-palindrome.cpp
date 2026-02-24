class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(int i = 0;i<s.size();i++){
           char ch = tolower(s[i]);
               if((ch>='a' && ch<='z') || (ch>='0'&&ch<='9')){
                    ss+=ch;
               }else continue;
        }
        string newSS = ss;
        reverse(ss.begin(),ss.end());
        return ss==newSS;
    }
};