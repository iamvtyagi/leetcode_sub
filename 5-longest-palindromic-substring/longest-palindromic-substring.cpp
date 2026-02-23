class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int k = i;
                int l = j;
                bool check = true;
                while(k<l){
                    if(s[k]==s[l]){
                        k++;
                        l--;
                    }else{
                        check = false;
                        break;
                    }
                }
                if(check){
                if(ans.size() < (j-i+1)){
                   ans = s.substr(i, j - i + 1);
                }
                }
            }
        }
        return ans;
    }
};