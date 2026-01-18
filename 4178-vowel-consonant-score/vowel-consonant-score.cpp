class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        unordered_set<char> st1= {'a','e','i','o','u'};
        unordered_set<char> st2 = {
        'b','c','d','f','g','h','j','k','l','m',
        'n','p','q','r','s','t','v','w','x','y','z'
        };
        int v = 0;
        int c= 0;
        for(int i = 0;i<n;i++){
            if(st1.find(s[i]) != st1.end()) v++;
            else if(st2.find(s[i]) != st2.end()) c++;
        }
        if(v==0 || c==0) return 0;
        return v/c;
    }
};