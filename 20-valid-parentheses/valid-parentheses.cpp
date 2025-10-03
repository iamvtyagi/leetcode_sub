class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        string s1 = "([{";
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s1.find(s[i]) != string::npos){  // check opening
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if((s[i] == ')' && top != '(') ||
                   (s[i] == ']' && top != '[') ||
                   (s[i] == '}' && top != '{')){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
