class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        int maxVow = 0;
        int maxCon = 0;
        unordered_set<char> st({'a','e','i','o','u','A','E','I','O','U'});
        vector<int> mp(26,0);
        for(auto el : s){
             mp[el-'a']++;
        }
        for(auto el : s){
            if(st.find(el) != st.end()){
                   maxVow = max(maxVow,mp[el-'a']);
            }else{
                maxCon = max(maxCon,mp[el-'a']);
            }
        }
        return maxVow + maxCon;
    }
};