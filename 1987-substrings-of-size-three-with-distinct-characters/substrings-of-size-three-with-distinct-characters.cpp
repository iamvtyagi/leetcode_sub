class Solution {
public:
    bool check(string &s, int i){
        return (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]);
    }

    int countGoodSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            if(j-i+1 < 3){
                j++;
            }
            else if(j-i+1==3){
                if(check(s,i)) ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};