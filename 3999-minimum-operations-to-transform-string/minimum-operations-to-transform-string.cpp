class Solution {
public:
    int minOperations(string s) {
        int mx = 0;
        for(auto x : s){
            if(x=='a') continue;
            mx = max('z'-x+1,mx);
        }
        return mx;
    }
};