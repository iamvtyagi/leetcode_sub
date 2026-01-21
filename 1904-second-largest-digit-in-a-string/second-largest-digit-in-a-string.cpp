class Solution {
public:
    int secondHighest(string s) {
        int n= s.size();
        set<int> st;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                st.insert(ch-'0');
            }
        }
        if(st.size()  < 2){
            return -1;
        }
            auto it = st.end();
            it--;
            it--;
            return *it;
    }
};