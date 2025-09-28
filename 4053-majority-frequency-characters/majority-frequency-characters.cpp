class Solution {
public:
    string majorityFrequencyGroup(string s) {
         int n = s.size();
        unordered_map<char,int> mp;
        unordered_map<int,vector<char>> mp2;
        int mx = 0;
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]] > mx){
                 mx = mp[s[i]];
            }
        }
        for(auto el : mp){
            mp2[el.second].push_back(el.first);
        }
        int maxFreq = 0;
        int grpSize = 0;
        for( auto el : mp2){
            if(el.second.size() > grpSize || el.second.size() == grpSize && el.first > maxFreq){
                maxFreq = el.first;
                grpSize = el.second.size();
            }
        }
        string ans = "";
        for(auto el : mp2[maxFreq]){
                  ans += el;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};