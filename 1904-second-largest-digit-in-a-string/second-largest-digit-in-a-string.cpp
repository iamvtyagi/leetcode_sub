class Solution {
public:
    int secondHighest(string s) {
        set<int> st;

        for(char ch : s){
            if(ch >= '0' && ch <= '9'){
                st.insert(ch - '0');
            }
        }

        if(st.size() < 2) return -1;

        auto it = st.end();
        it--;  
        it--;     

        return *it;
    }
};
