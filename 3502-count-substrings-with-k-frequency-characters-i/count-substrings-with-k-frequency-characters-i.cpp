class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j = i;j<n;j++){
                mp[s[j]]++;
                if(mp[s[j]]>=k){
                    cnt++;
                    cnt += (n-j-1);
                    break;
                }
            }
        }
        return cnt;
    }
};