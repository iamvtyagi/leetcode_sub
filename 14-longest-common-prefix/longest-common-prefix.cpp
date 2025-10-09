class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int minLength = INT_MAX;
        for(int i = 0;i<n;i++){
             int b = strs[i].size();
             minLength = min(minLength , b);
        }
        int cnt = 0;
        for(int i = 0;i<minLength;i++){
             
            for(int j = 0;j<n-1;j++){
                if(strs[j][i] != strs[j+1][i]){
                    return ans;
                }
            }
            ans += strs[0][cnt++];
        }
        return ans;
    }
};