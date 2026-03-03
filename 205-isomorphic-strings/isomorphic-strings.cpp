class Solution {
public:
    bool check(string s , string t){
        unordered_map<char,char> mp;
        int n = s.size();
        int m = t.size();
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(mp.find(ch) != mp.end()){
                if(mp[ch] != t[i]) return false;
            }else{
                mp[ch] = t[i];
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return check(s,t) && check(t,s);
    }
};