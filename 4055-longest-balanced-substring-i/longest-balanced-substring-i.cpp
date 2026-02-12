class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0;i<n;i++){
            unordered_map<char,int> mp;
             for(int j = i;j<n;j++){
                 mp[s[j]]++;

                 // string sbs = s.substr(i,j-i+1);

                 int firstFreq = mp.begin()->second; //begin gives pointer
                 bool check = true;

                 for(auto& el : mp){
                      if(el.second != firstFreq){
                          check = false;
                          break;
                      }
                 }

                 if(check) {
                     maxLen = max(maxLen,j-i+1);
                 }
             }
         }
        return maxLen;
    }
};